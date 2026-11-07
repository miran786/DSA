from reportlab.lib.pagesizes import A4, landscape
from reportlab.lib.units import inch
from reportlab.lib import colors
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle, Paragraph
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.enums import TA_CENTER, TA_LEFT

styles = getSampleStyleSheet()

title_style = ParagraphStyle('TitleC', parent=styles['Title'], fontSize=15, spaceAfter=2, alignment=TA_LEFT)
sub_style = ParagraphStyle('SubC', parent=styles['Normal'], fontSize=8.5, textColor=colors.grey, alignment=TA_LEFT, spaceAfter=8)

cell_style = ParagraphStyle('Cell', parent=styles['Normal'], fontSize=8, leading=9.5, alignment=TA_LEFT)
week_style = ParagraphStyle('Week', parent=styles['Normal'], fontSize=8.5, leading=10, alignment=TA_CENTER, fontName='Helvetica-Bold')
date_style = ParagraphStyle('Date', parent=styles['Normal'], fontSize=7.5, leading=9, alignment=TA_CENTER, textColor=colors.HexColor('#444444'))
header_style = ParagraphStyle('Header', parent=styles['Normal'], fontSize=8.5, leading=10, alignment=TA_CENTER, textColor=colors.white, fontName='Helvetica-Bold')
check_style = ParagraphStyle('Check', parent=styles['Normal'], fontSize=11, alignment=TA_CENTER, fontName='Helvetica-Bold')
dash_style = ParagraphStyle('Dash', parent=styles['Normal'], fontSize=8, alignment=TA_CENTER, textColor=colors.grey)
note_style = ParagraphStyle('Note', parent=styles['Normal'], fontSize=7.5, leading=9, alignment=TA_LEFT, textColor=colors.HexColor('#444444'))

def P(text, style=cell_style):
    return Paragraph(text, style)

CHK = P('[ ]', check_style)
DASH = P('\u2014', dash_style)

weeks = [
    (1, 'Aug 20-24', 'Arrays, Basic Math', None, 'Log every problem: cold / hint / couldn\'t-solve.'),
    (2, 'Aug 25-31', 'Sorting, Binary Search (1D + on answer), Basic Strings', None, ''),
    (3, 'Sep 1-7', 'Recursion basics \u2014 subsets, permutations', 'OS \u2014 Processes &amp; Threads', ''),
    (4, 'Sep 8-14', 'Backtracking \u2014 N-Queens, Sudoku', 'OS \u2014 Deadlocks &amp; Paging', ''),
    (5, 'Sep 15-21', 'Linked List \u2014 singly, doubly, cycle detection, reversal, merge', 'CN basics \u2014 OSI / TCP-IP model', ''),
    (6, 'Sep 22-30', 'Two Pointers + Sliding Window (fixed &amp; variable)', 'CN basics \u2014 HTTP, TCP vs UDP', ''),
    (7, 'Oct 1-7', 'Binary Trees \u2014 traversals, views', 'LLD \u2014 SOLID principles', ''),
    (8, 'Oct 8-14', 'BST \u2014 LCA, diameter, BST-specific ops', 'LLD \u2014 Parking Lot design', ''),
    (9, 'Oct 15-21', 'Graphs pt.1 \u2014 BFS/DFS, topological sort', 'LLD \u2014 Rate Limiter design', ''),
    (10, 'Oct 22-31', 'Graphs pt.2 \u2014 Dijkstra/Bellman-Ford, Union-Find, MST', 'LLD \u2014 review &amp; consolidate', 'Checkpoint: re-solve every Aug/Sept \u2018hint\u2019 problem.'),
    (11, 'Nov 1-7', 'DP pt.1 \u2014 1D, 2D/grid', 'STAR story \u2014 Patent (AI CCTV anomaly detection)', ''),
    (12, 'Nov 8-14', 'DP pt.2 \u2014 knapsack variants, LIS family, string DP', 'STAR story \u2014 IEEE paper (ICOSEC 2025)', ''),
    (13, 'Nov 15-21', 'Greedy + Heaps / Priority Queue', 'STAR story \u2014 SHL score 4\u219293 turnaround', ''),
    (14, 'Nov 22-30', 'Tries + leftovers (bit manipulation, advanced stacks/queues)', 'STAR story \u2014 G3 Product work; review all stories', ''),
    (15, 'Dec 1-7', 'Close remaining sheet topics', 'Review CS fundamentals (weak areas)', ''),
    (16, 'Dec 8-14', 'Full weak-topic re-audit \u2014 all months', 'Review LLD concepts', 'Checkpoint: re-solve everything ever flagged \u2018hint\u2019.'),
    (17, 'Dec 15-21', 'Final revision pt.1', 'Light review only', ''),
    (18, 'Dec 22-31', 'Final revision pt.2', 'Light review only', 'Taper \u2014 rest matters more than one more problem here.'),
]

data = [[
    P('Wk', header_style), P('Dates', header_style), P('DSA Topic to Complete', header_style),
    P('Done', header_style), P('Fundamentals Topic', header_style), P('Done', header_style), P('Notes', header_style),
]]

for wk, dates, dsa, fund, note in weeks:
    data.append([
        [P(f'{wk}', week_style)], [P(dates, date_style)], P(dsa), CHK,
        P(fund) if fund else DASH, CHK if fund else DASH,
        P(note, note_style) if note else P('', note_style),
    ])

col_widths = [0.42*inch, 0.8*inch, 3.55*inch, 0.42*inch, 2.65*inch, 0.42*inch, 2.35*inch]
table = Table(data, colWidths=col_widths, repeatRows=1)

style_cmds = [
    ('BACKGROUND', (0, 0), (-1, 0), colors.HexColor('#2b2b2b')),
    ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'),
    ('GRID', (0, 0), (-1, -1), 0.6, colors.HexColor('#888888')),
    ('BOX', (0, 0), (-1, -1), 1.1, colors.black),
    ('TOPPADDING', (0, 0), (-1, -1), 4), ('BOTTOMPADDING', (0, 0), (-1, -1), 4),
    ('LEFTPADDING', (0, 0), (-1, -1), 4), ('RIGHTPADDING', (0, 0), (-1, -1), 4),
    ('ROWBACKGROUNDS', (0, 1), (-1, -1), [colors.white, colors.HexColor('#f5f5f5')]),
]
for row in [1, 2]:
    style_cmds.append(('BACKGROUND', (4, row), (5, row), colors.HexColor('#eaeaea')))
table.setStyle(TableStyle(style_cmds))

doc = SimpleDocTemplate(
    'maang-prep-weekly-timeline.pdf', pagesize=landscape(A4),
    leftMargin=0.35*inch, rightMargin=0.35*inch,
    topMargin=0.4*inch, bottomMargin=0.35*inch,
    title='MAANG Prep Weekly Timeline'
)

doc.build([
    Paragraph('MAANG / FAANG Prep \u2014 Week-by-Week Timeline (Aug\u2013Dec 2026)', title_style),
    Paragraph('Striver\'s Sheet. One topic to finish per week \u2014 tick [ ] Done when it\'s actually done, not just started.', sub_style),
    table,
])
print('PDF built successfully')
