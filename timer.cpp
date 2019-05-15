#include<iostream>
#include<ctime>
#include<unistd.h>

using namespace std;

class Clock{
private:
	int hour;
	int minute;
	int second;

public:
	Clock(int h, int m, int s);
	void set(int h, int m, int s);
	void run_through_sleep();
	void run_through_caculate();
	void show(); 	//show Clock which is set
	string getTime();
};

Clock::Clock(int h, int m, int s):hour(h), minute(m), second(s){}

void Clock::show()
{
	cout<<'\r';
	if(this->hour < 10) cout<<0;	//小于10需要占位符
	cout << this->hour << ':';

	if(this->minute < 10) cout<<0;	//小于10需要占位符
	cout << this->minute << ':';

	if(this->second < 10) cout<<0;	//小于10需要占位符
	cout << this->second << endl;
}

string Clock::getTime()
{
	time_t now = time(NULL);
	char* dt = ctime(&now);
	return dt;
}

void Clock::run_through_sleep()
{
	//输出开始计时时间
	cout << "start->" << getTime();
	
	//度过时间
	sleep(second + minute*60 + hour*minute*60);
	
	//输出经过的时间
	cout << "||\n||\n\\/"<<endl;;
	Clock::show();
	cout << "/\\\n||\n||\n"<<endl;
	cout << "Time out!!!!!!" << endl;

	//输出结束计时时间
	cout << "end->" << getTime()<<endl;
}


void Clock::run_through_caculate()
{
	//输出开始计时时间
	cout << "start->" << getTime() << endl;

	//开始计时
	while(hour || minute || second)	//设置程序结束
	{
	    sleep(1);//等待1S
	    if(--second < 0)
	    {
	        second = 59;
	        if(--minute < 0)
	        {
	          minute = 59;
	          --hour;
	        }
	    }
    }

    //剩余时间
    cout << "remainder==>"
    Clock::show();

	//输出结束计时时间
	cout << "end->" << getTime()<<endl;
}

int main()
{
	int hour, minute, second;
	cout << "please input Clock: hour minute second" << endl;
	cin>> hour >> minute >> second;
	Clock t(hour, minute, second);
	t.run_through_caculate();
	return 0;
}