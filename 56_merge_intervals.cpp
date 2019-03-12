bool compare(const Interval & a, const Interval & b){
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals){
        if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> ans;
        Interval temp;
        for(auto i = intervals.begin(); i != intervals.end(); ++i){
            if(i == intervals.begin()){
                temp.start = i->start;
                temp.end = i->end;
            }
            else if(i->start <= temp.end){
                if(i->end > temp.end){
                    temp.end = i->end;
                }
            }
            else{
                ans.push_back(temp);
                temp.start = i->start;
                temp.end = i->end;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};