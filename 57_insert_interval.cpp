class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int i;
        for(i = 0; i < intervals.size() && intervals[i].end < newInterval.start; ++i){
            ans.push_back(intervals[i]);
        }
        if(i == intervals.size()){
            ans.push_back(newInterval);
        }
        else{
            if(intervals[i].start > newInterval.end){
                ans.push_back(newInterval);
                for(int j = i; j < intervals.size(); ++j){
                    ans.push_back(intervals[j]);
                }
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end){
                for(int j = i; j < intervals.size(); ++j){
                    ans.push_back(intervals[j]);
                }
            }
            else if(intervals[i].start <= newInterval.end && newInterval.start <= intervals[i].start && newInterval.end <= intervals[i].end){
                newInterval.end = intervals[i].end;
                ans.push_back(newInterval);
                for(int j = i+1; j < intervals.size(); ++j){
                    ans.push_back(intervals[j]);
                }
            }
            else if(newInterval.start >= intervals[i].start && newInterval.end >= intervals[i].end){
                newInterval.start = intervals[i].start;
                while(i < intervals.size() && intervals[i].end <= newInterval.end){
                    i++;
                }
                if(i == intervals.size()){
                    ans.push_back(newInterval);
                }
                else if(intervals[i].start > newInterval.end){
                    ans.push_back(newInterval);
                    for(int j = i; j < intervals.size(); ++j){
                        ans.push_back(intervals[j]);
                    }
                }
                else{
                    newInterval.end = intervals[i].end;
                    ans.push_back(newInterval);
                    for(int j = i+1; j < intervals.size(); ++j){
                        ans.push_back(intervals[j]);
                    }
                }
            }
            else if(newInterval.start <= intervals[i].start && newInterval.end > intervals[i].end){
                while(i < intervals.size() && intervals[i].end <= newInterval.end){
                    i++;
                }
                if(i == intervals.size()){
                    ans.push_back(newInterval);
                }
                else if(intervals[i].start > newInterval.end){
                    ans.push_back(newInterval);
                    for(int j = i; j < intervals.size(); ++j){
                        ans.push_back(intervals[j]);
                    }
                }
                else{
                    newInterval.end = intervals[i].end;
                    ans.push_back(newInterval);
                    for(int j = i+1; j < intervals.size(); ++j){
                        ans.push_back(intervals[j]);
                    }
                }
            }
        }
        return ans;
    }
};