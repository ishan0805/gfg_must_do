class Solution
{

public:
    pair<int, int> findPosition(int number, vector<vector<int> > &board)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (board[i][j] == number)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    int minThrow(int n, int arr[])
    {
        vector<vector<int> > visited(5, vector<int>(6, 0));
        vector<vector<int> > board(5, vector<int>(6, 0));
        int s = 1;
        int flag = 1;
        for (int i = 0; i < 5; i++)
        {
            if (flag)
            {
                for (int j = 0; j < 6; j++)
                {
                    board[i][j] = s++;
                }
            }
            else
            {
                for (int j = 5; j >= 0; j--)
                {
                    board[i][j] = s++;
                }
            }
            flag ^= 1;
        }
        unordered_map<int, int> ladders;
        unordered_map<int, int> snakes;

        for (int i = 0; i < n * 2; i += 2)
        {
            if (arr[i] < arr[i + 1])
            {
                ladders[arr[i]] = arr[i + 1];
                //cout<<arr[i] <<arr[i+1]
            }
            else
            {
                snakes[arr[i]] = arr[i + 1];
            }
        }
        queue<pair<int, int> > q;
        q.push({0, 0});
        int ans = 0;
        while (!q.empty())
        {

            int size = q.size();

            while (size--)
            {
                auto curr_pos = q.front();
                q.pop();
                int curr_i = curr_pos.first;
                int curr_j = curr_pos.second;
                visited[curr_i][curr_j] = 1;

                int number = board[curr_i][curr_j];
                for (int step = 0; step < 6; step++)
                {

                    number++;
                    if (number > 30)
                    {
                        break;
                    }
                    int i = findPosition(number, board).first;
                    int j = findPosition(number, board).second;
                    if (visited[i][j] == 0)
                    {

                        if (snakes.find(number) != snakes.end())
                        {
                            auto now_pos = findPosition(snakes[number], board);

                            if (visited[now_pos.first][now_pos.second] == 1)
                            {
                                continue;
                            }
                            q.push({now_pos.first, now_pos.second});
                            visited[now_pos.first][now_pos.second] = 1;
                        }
                        else if (ladders.find(number) != ladders.end())
                        {
                            auto now_pos = findPosition(ladders[number], board);

                            if (visited[now_pos.first][now_pos.second] == 1)
                            {
                                continue;
                            }
                            q.push({now_pos.first, now_pos.second});
                            visited[now_pos.first][now_pos.second] = 1;
                        }

                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
            ans++;
            /* for(int i=0;i<5;i++)
           {
               for(int j=0;j<6;j++)
               {
                   cout<<visited[i][j]<<" ";
               }
               cout<<"\n";
           }*/
            // cout<<ladders[3];

            //cout<<ans<<"\n";
            if (visited[4][5] == 1)
            {
                return ans;
            }
        }
        return ans;
    }
};