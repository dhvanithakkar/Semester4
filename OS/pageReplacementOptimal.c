#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    int pages[] = {6, 0, 12, 0, 30, 4, 2, 30, 32, 1, 20, 15};
    int no_fr = 3;
    int no_pages = sizeof(pages)/sizeof(pages[0]);

    int frames[no_fr];
    memset(frames, -1, sizeof(frames));
    int miss = 0;

    printf("\nOptimal\n");
    for (int time = 0; time < no_pages; time++) {
        int page = pages[time];
        int found = 0;

        for (int i = 0; i < no_fr; i++) {
            if (frames[i] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int empty_index = -1;
            for (int i = 0; i < no_fr; i++) {
                if (frames[i] == -1) {
                    empty_index = i;
                    break;
                }
            }

            if (empty_index != -1) {
                frames[empty_index] = page;
                miss++;
            } else {
                int future_pages[no_fr];
                int frame_future_freq[no_fr];
                memset(frame_future_freq, 0, sizeof(frame_future_freq));

                for (int i = 0; i < no_fr; i++) {
                    for (int j = time + 1; j < time + 1 + no_fr && j < no_pages; j++) {
                        if (frames[i] == pages[j]) {
                            frame_future_freq[i]++;
                        }
                    }
                }

                int min_future_freq = frame_future_freq[0];
                int frame_changed = 0;
                for (int i = 1; i < no_fr; i++) {
                    if (frame_future_freq[i] < min_future_freq) {
                        min_future_freq = frame_future_freq[i];
                        frame_changed = i;
                    }
                }

                frames[frame_changed] = page;
                miss++;
            }
        }

        printf("%d :", page);
        for (int i = 0; i < no_fr; i++) {
            printf(" %d", frames[i]);
        }
        printf("\n");
    }

    printf("Misses = %d/%d\n", miss, no_pages);
    printf("Hits   = %d/%d\n", no_pages - miss, no_pages);
}
