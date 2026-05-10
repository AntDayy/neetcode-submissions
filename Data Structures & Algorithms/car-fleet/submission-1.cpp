class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        stack<double> time;
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.rbegin(), cars.rend());
        for (int i = 0; i < position.size(); i++)
        {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if (time.empty() || t > time.top())
            {
                time.push(t);
            }
        }
        return time.size();
    }
};