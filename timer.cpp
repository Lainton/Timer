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
	void run_through_sleep();		//通过sleep的方式计时
	void run_through_caculate();	//通过运算的方式计时
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

	    //s 走完了 m-1。如果m 已经为0 则h-1 如果h没有就说明 0 0 0了
	    if(--second < 0)	//如果s到了0  没到就跳过
	    {
	        second = 59;	//将s设为59
	        if(--minute < 0)	//判断分钟有没有到0 没到就跳过分钟位置的变化
	        {
	          minute = 59;		//分钟到了0 就重新设置为59
	          --hour;
	        }
	    }
    }

    //剩余时间
    cout << "remainder==>";
    Clock::show();

	//输出结束计时时间
	cout << "end->" << getTime()<<endl;
}

int main()
{
	int hour, minute, second;

	//提示输入倒计时时间
	cout << "please input Clock: hour minute second" << endl;

	//获取倒计时时间
	cin>> hour >> minute >> second;

	//Clock类实例化
	Clock t(hour, minute, second);

	//允许
	t.run_through_sleep();

	
	return 0;
}