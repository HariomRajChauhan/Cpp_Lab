#include <iostream>

class Timer
{
private:
    int hour;
    int minute;
    int second;

public:
    void getdata()
    {
        std::cout << "\n\tSet Starting Time" << std::endl;
        std::cout << "Enter Hours : ";
        std::cin >> hour;
        std::cout << "Enter Minutes : ";
        std::cin >> minute;
        std::cout << "Enter Seconds : ";
        std::cin >> second;
    }

    void Display()
    {
        std::cout << "Time : " << hour << ":" << minute << ":" << second << std::endl;
    }

    void IncrementTime()
    {
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                }
            }
        }
        std::system("sleep 0.6");
        system("clear");
    }
};
int main()
{
    Timer t;
    t.getdata();

    system("clear");
    while(true)
    {

        t.IncrementTime();
        t.Display();
    }

    return 0;
}