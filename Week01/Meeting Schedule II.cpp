/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startingTime, endingTime;
        for(auto it : intervals) {
            startingTime.push_back(it.start);
            endingTime.push_back(it.end);
        }
        sort(startingTime.begin(), startingTime.end());
        sort(endingTime.begin(), endingTime.end());

        int min_rooms = 0; int count_rooms = 0;
        int start = 0; int end = 0;
        while(start < startingTime.size()) {
            if(startingTime[start] < endingTime[end]) {
                count_rooms++;
                min_rooms = max(min_rooms, count_rooms);
                start++;
            }
            else {
                count_rooms--;
                end++;
            }
        }
        return min_rooms;
    }
};
