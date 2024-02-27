# no_pg = int(input("Enter number of Pages: "))

pages = [6, 0, 12, 0, 30, 4, 2, 30, 32, 1, 20, 15]
# pages = [2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5]

# pages = []
# for i in range(no_pg):
#     page = int(input(f"Enter page number for step {i+1}: "))
#     pages.append(page)

no_fr = int(input("Enter number of Frames: "))

def fifo(pages, no_fr):
    frames = [-1] * no_fr
    in_time = [0] * len(pages)
    miss = 0
    
    print("\nFirst in First Out")
    for time, page in enumerate(pages):
        min_t = in_time[0]
        oldest_page = 0
        page_assigned = False
        if page not in frames:
            for frame_no, frame in enumerate(frames):
                if frame == -1:
                    frames[frame_no] = page
                    in_time[frame_no] = time
                    page_assigned = True
                    miss += 1
                    break

                if in_time[frame_no] < min_t:
                    min_t = in_time[frame_no]
                    oldest_page = frame_no
        
            if not page_assigned:
                frames[oldest_page] = page
                in_time[oldest_page] = time
                miss += 1
        
        print(page, ":", frames)

    print(f"Misses = {miss}/{len(pages)}")
    print(f"Hits   = {len(pages) - miss}/{len(pages)}")

def lru(pages, no_fr):
    frames = [-1] * no_fr
    lru = []
    miss = 0

    print("\nLeast Recently Used")
    for page in pages:
        page_assigned = False

        if page not in frames:
            for frame_no, frame in enumerate(frames):
                if frame == -1:
                    frames[frame_no] = page
                    page_assigned = True
                    miss += 1
                    break

        
            if not page_assigned:
                lru_page = lru[0]
                frame_changed = frames.index(lru_page)
                lru.remove(frames[frame_changed])
                frames[frame_changed] = page
                miss += 1
            
        if page in lru:
            lru.remove(page)
        lru.append(page)
        
        print(page, ":", frames)

    print(f"Misses = {miss}/{len(pages)}")
    print(f"Hits   = {len(pages) - miss}/{len(pages)}")

def optimal(pages, no_fr):
    frames = [-1] * no_fr
    lru = []
    miss = 0

    print("\nOptimal")
    for time, page in enumerate(pages):
        if page not in frames:
            if -1 in frames:
                frame_no = frames.index(-1)
                frames[frame_no] = page
                miss += 1

                if page in lru:
                    lru.remove(page)
                lru.append(page)

            else:
                future_pages = pages[time + 1: time + 1 + no_fr]
                frame_future_freq = [future_pages.count(frame) for frame in frames]

                min_future_freq = min(frame_future_freq)

                frame_changed = frame_future_freq.index(min_future_freq)
                
                frames[frame_changed] = page
                miss += 1
        
        print(page, ":", frames)

    print(f"Misses = {miss}/{len(pages)}")
    print(f"Hits   = {len(pages) - miss}/{len(pages)}")


fifo(pages, no_fr)
lru(pages, no_fr)
optimal(pages, no_fr)
