import sys

S_BOX = {
    0x0: 0x9, 0x1: 0x4, 0x2: 0xA, 0x3: 0xB,
    0x4: 0xD, 0x5: 0x1, 0x6: 0x8, 0x7: 0x5,
    0x8: 0x6, 0x9: 0x2, 0xA: 0x0, 0xB: 0x3,
    0xC: 0xC, 0xD: 0xE, 0xE: 0xF, 0xF: 0x7
}

INV_S_BOX = {v: k for k, v in S_BOX.items()}

RCON = [0x80, 0x30]

def sub_nibbles(block, sbox):
    n1 = (block >> 12) & 0xF
    n2 = (block >> 8) & 0xF
    n3 = (block >> 4) & 0xF
    n4 = block & 0xF
    
    return (sbox[n1] << 12) | (sbox[n2] << 8) | (sbox[n3] << 4) | sbox[n4]

def shift_rows(block):
    return ((block & 0xF000) | ((block & 0x000F) << 8) | 
            (block & 0x00F0) | ((block & 0x0F00) >> 8))

def gf_mult(a, b):
    p = 0
    for i in range(4):
        if (b & 1): p ^= a
        hi_bit_set = (a & 0x8)
        a <<= 1
        if hi_bit_set: a ^= 0x13
        a &= 0xF
        b >>= 1
    return p & 0xF

def mix_columns(block):
    n1 = (block >> 12) & 0xF
    n2 = (block >> 8) & 0xF
    n3 = (block >> 4) & 0xF
    n4 = block & 0xF

    m1 = n1 ^ gf_mult(0x4, n2)
    m2 = gf_mult(0x4, n1) ^ n2
    m3 = n3 ^ gf_mult(0x4, n4)
    m4 = gf_mult(0x4, n3) ^ n4
    
    return (m1 << 12) | (m2 << 8) | (m3 << 4) | m4

def inv_mix_columns(block):
    n1 = (block >> 12) & 0xF
    n2 = (block >> 8) & 0xF
    n3 = (block >> 4) & 0xF
    n4 = block & 0xF
    
    m1 = gf_mult(0x9, n1) ^ gf_mult(0x2, n2)
    m2 = gf_mult(0x2, n1) ^ gf_mult(0x9, n2)
    m3 = gf_mult(0x9, n3) ^ gf_mult(0x2, n4)
    m4 = gf_mult(0x2, n3) ^ gf_mult(0x9, n4)
    
    return (m1 << 12) | (m2 << 8) | (m3 << 4) | m4

def key_expansion(key):
    w = [0] * 6
    w[0] = (key >> 8) & 0xFF
    w[1] = key & 0xFF
    
    for i in range(2):
        temp = w[2*i + 1]
        n1 = (temp >> 4) & 0xF
        n2 = temp & 0xF
        temp = (S_BOX[n2] << 4) | S_BOX[n1]
        
        rcon_val = RCON[i]
        w[2*i + 2] = w[2*i] ^ temp ^ rcon_val
        w[2*i + 3] = w[2*i + 2] ^ w[2*i + 1]
        
    k0 = (w[0] << 8) | w[1]
    k1 = (w[2] << 8) | w[3]
    k2 = (w[4] << 8) | w[5]
    return k0, k1, k2

def encrypt(plaintext, key):
    k0, k1, k2 = key_expansion(key)
    
    state = plaintext ^ k0
    
    state = sub_nibbles(state, S_BOX)
    state = shift_rows(state)
    state = mix_columns(state)
    state = state ^ k1
    
    state = sub_nibbles(state, S_BOX)
    state = shift_rows(state)
    state = state ^ k2
    
    return state

def decrypt(ciphertext, key):
    k0, k1, k2 = key_expansion(key)
    
    state = ciphertext ^ k2
    state = shift_rows(state)
    state = sub_nibbles(state, INV_S_BOX)
    
    state = state ^ k1
    state = inv_mix_columns(state)
    state = shift_rows(state)
    state = sub_nibbles(state, INV_S_BOX)
    
    state = state ^ k0
    
    return state

if __name__ == "__main__":
    plaintext = 0b1101011100101000
    key       = 0b0100101011110101

    print(f"Original Plaintext: {bin(plaintext)} ({hex(plaintext)})")
    print(f"Key:                {bin(key)} ({hex(key)})")
    
    encrypted = encrypt(plaintext, key)
    print(f"Encrypted Cipher:   {bin(encrypted)} ({hex(encrypted)})")
    
    decrypted = decrypt(encrypted, key)
    print(f"Decrypted Text:     {bin(decrypted)} ({hex(decrypted)})")