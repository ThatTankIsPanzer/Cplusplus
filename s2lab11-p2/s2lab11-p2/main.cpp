#include <iostream>
#include <string>
#include <algorithm> // std::sort
using namespace std;
int main()
{
    int ai;
    int si;

    while (cin >> ai >> si)
    {
        int count = 0;  //houses
        int a[30000] = {}; //avenue
        int s[30000] = {}; //street
        float ba = 0;//bestloc avenue
        float bs = 0;//bestloc street
        int dist = 0;
        string aLine;

        a[count] = ai;
        s[count] = si;
        count++;

        getline(cin, aLine);
        for (int i = 1; aLine[i] == ' ' && i < aLine.size(); i++)
        {
            for (; aLine[i] == ' ' && i < aLine.size(); i++);
            for (int j = 1; aLine[i] != ' ' && i < aLine.size(); i++, j *= 10)
            {
                if (j >= 10)
                    a[count] *= 10;
                aLine[i] = aLine[i] - '0';
                a[count] += aLine[i];
            }

            for (; aLine[i] == ' ' && i < aLine.size(); i++);
            for (int j = 1; aLine[i] != ' ' && i < aLine.size(); i++, j *= 10)
            {
                if(j >= 10)
                    s[count] *= 10;
                aLine[i] = aLine[i] - '0';
                s[count] += aLine[i];
            }
            count++;
        }

        sort(a, a + count);
        sort(s, s + count);

        ba = a[count / 2];
        bs = s[count / 2];

        for (int i = 0; i < count; i++)
        {
            dist += abs(a[i] - ba);
            dist += abs(s[i] - bs);
        }
        cout << dist << endl;
    }
}


