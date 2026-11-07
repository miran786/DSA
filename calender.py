import datetime

# --- CONFIGURATION ---
SEMESTER_START = datetime.datetime(2026, 1, 5)  # Jan 5, 2026
SEMESTER_END = "20260531T235959Z"                 # May 31, 2026
# Mapping of short codes to full subject names & teachers for context
SUBJECTS = {
    "SE": "Software Engineering (SDK)",
    "DL": "Deep Learning (SSB)",
    "CSAB": "Cyber Security & Blockchain (MNP/SYB)",
    "DT": "Design Thinking (PCK/NBK)"
}

def create_event(title, day_offset, start_hour, duration_hours, location):
    """
    Creates a single event string in ICS format.
    day_offset: 0=Monday, 1=Tuesday, ... 4=Friday
    """
    # Calculate the first occurrence of this weekday on/after start date
    current_date = SEMESTER_START
    while current_date.weekday() != day_offset:
        current_date += datetime.timedelta(days=1)
    
    start_dt = current_date.replace(hour=start_hour, minute=0, second=0)
    end_dt = start_dt + datetime.timedelta(hours=duration_hours)
    
    # Format dates for ICS
    fmt = "%Y%m%dT%H%M%S"
    
    event = [
        "BEGIN:VEVENT",
        f"SUMMARY:{title}",
        f"DTSTART;TZID=Asia/Kolkata:{start_dt.strftime(fmt)}",
        f"DTEND;TZID=Asia/Kolkata:{end_dt.strftime(fmt)}",
        f"RRULE:FREQ=WEEKLY;UNTIL={SEMESTER_END}",
        f"LOCATION:{location}",
        "END:VEVENT"
    ]
    return "\n".join(event)

# --- SCHEDULE DATA ---
# Format: (Day_Index, Start_Hour, Duration, Subject, Location, Type)
# Day Index: 0=Mon, 1=Tue, 2=Wed, 3=Thu, 4=Fri

# 1. COMMON THEORY CLASSES (Everyone attends these)
common_events = [
    (1, 12, 1, "SE", "2206", "Theory"),    # Tue 12-1
    (1, 13, 1, "DL", "2206", "Theory"),    # Tue 1-2
    (2, 14, 1, "CSAB", "3305", "Theory"),  # Wed 2-3
    (2, 15, 1, "DL", "3305", "Theory"),    # Wed 3-4
    (3, 16, 1, "CSAB", "3305", "Theory"),  # Thu 4-5
    (3, 17, 1, "SE", "3305", "Theory"),    # Thu 5-6
]

# 2. BATCH SPECIFIC CLASSES (Labs & Tutorials)
# Dictionary keys are 'B1', 'B2', 'B3'
batch_schedules = {
    "B1": [
        (1, 11, 1, "SE", "3305", "Tutorial"),     # Tue 11-12
        (1, 14, 1, "CSAB", "2206", "Tutorial"),   # Tue 2-3
        (2, 16, 1, "DL", "3105", "Tutorial"),     # Wed 4-5
        (3, 14, 2, "DL", "2308", "Lab"),          # Thu 2-4
        (4, 8, 2, "CSAB", "3108B", "Lab"),        # Fri 8-10
        (4, 8, 2, "SE", "3108A", "Lab"),          # Fri 8-10 (Check if conflict in src, listed both)
        # Note: Wednesday DT-6 Tutorial is complex, often separate. Added generic slot below.
        (2, 10, 1, "DT", "681", "Tutorial"),      # Wed 10-11
    ],
    "B2": [
        (2, 16, 1, "SE", "3305", "Tutorial"),     # Wed 4-5
        (2, 17, 1, "DL", "3304", "Tutorial"),     # Wed 5-6
        (3, 14, 2, "SE", "3108B", "Lab"),         # Thu 2-4
        (4, 14, 2, "CSAB", "3108B", "Lab"),       # Fri 2-4
        (4, 14, 2, "DL", "3108A", "Lab"),         # Fri 2-4
        (2, 10, 1, "DT", "683", "Tutorial"),      # Wed 10-11
    ],
    "B3": [
        (1, 15, 1, "DL", "3105", "Tutorial"),     # Tue 3-4
        (2, 17, 1, "SE", "2206", "Tutorial"),     # Wed 5-6
        (4, 8, 2, "DL", "3205B", "Lab"),          # Fri 8-10
        (4, 8, 1, "CSAB", "3304", "Tutorial"),    # Fri 8-9
        (4, 14, 2, "SE", "3205B", "Lab"),         # Fri 2-4
        (4, 14, 2, "CSAB", "3205B", "Lab"),       # Fri 2-4
        (2, 10, 1, "DT", "683", "Tutorial"),      # Wed 10-11
    ]
}

def main():
    print("--- VIT Timetable Generator ---")
    batch = input("Enter your Batch (B1, B2, or B3): ").upper().strip()
    
    if batch not in batch_schedules:
        print("Invalid batch! Defaulting to showing ALL batches (you can delete later).")
        user_schedule = batch_schedules["B1"] + batch_schedules["B2"] + batch_schedules["B3"]
    else:
        user_schedule = batch_schedules[batch]

    # Header for ICS file
    ics_content = [
        "BEGIN:VCALENDAR",
        "VERSION:2.0",
        "PRODID:-//VIT PUNE//TIMETABLE//EN",
        "CALSCALE:GREGORIAN",
        "METHOD:PUBLISH",
        "X-WR-TIMEZONE:Asia/Kolkata"
    ]

    # Process Common Theory
    for day, hour, dur, subj, room, type_ in common_events:
        title = f"{subj} {type_}"
        ics_content.append(create_event(title, day, hour, dur, f"Room {room}"))

    # Process Batch Specific
    for day, hour, dur, subj, room, type_ in user_schedule:
        title = f"{subj} {type_}"
        ics_content.append(create_event(title, day, hour, dur, f"Room {room}"))

    ics_content.append("END:VCALENDAR")

    # Write to file
    filename = "timetable.ics"
    with open(filename, "w") as f:
        f.write("\n".join(ics_content))
    
    print(f"\nSuccess! '{filename}' has been created.")
    print("You can now drag this file into Google Calendar or Outlook.")

if __name__ == "__main__":
    main()