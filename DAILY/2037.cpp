class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int i = 0;
        int mv = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(i = 0;i<seats.size();i++)
        {
            mv += abs(students[i]-seats[i]);
        }
        return mv;
    }
};
