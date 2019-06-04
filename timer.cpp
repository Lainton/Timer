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
    void run_through_calculate();	//通过运算的方式计时
    void show(); 	//show Clock which is
    string getTime();	//show local time
    string getRestTime();
};

Clock::Clock(int h, int m, int s):hour(h), minute(m), second(s){}

void Clock::set(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}

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

string Clock::getRestTime()
{
    string restTime = to_string(this->hour)+':'+to_string(this->minute)+':'+to_string(this->second);
    return restTime;
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


void Clock::run_through_calculate()
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

        //输出剩余时间
        cout << Clock::getRestTime() << endl;
    }


    //输出结束计时时间
    cout << "end->" << getTime()<<endl;
}

void help()
{
    cout<<"此程序用于倒计时"<<endl;
    cout<<"timer [-hscHMS]"<<endl;
    cout<<"\t-h help"<<endl;
    cout<<"\t-s run with sleep function(without display of time)"<<endl;
    cout<<"\t-c run with calculate function"<<endl;
    cout<<"\t-H set Hour"<<endl;
    cout<<"\t-M set Minute"<<endl;
    cout<<"\t-S set Second"<<endl;
}



class cmdResolve{
private:
    //开关
    bool sleep;
    bool calculate;

    bool help;
    bool err;

    int Hour;
    int Minute;
    int Second;

public:
    //开关控制函数
    cmdResolve();	//初始化
    void setPara(int argc, char *argv[]); //设置参数
    //获取参数
    bool getsleep();
    bool getcalculate();

    bool gethelp();
    bool geterr();

    int getHour();
    int getMinute();
    int getSecond();


};

//初始化
cmdResolve::cmdResolve()
{
    sleep = false;
    calculate = false;
    help = false;
    err = false;
    Hour = 0;
    Minute = 0;
    Second = 0;

}

//解析参数
void cmdResolve::setPara(int argc, char *argv[])
{
    //命令行解析output
    int o;

    //设置参数字符串
    const char *optstirng = "schH:M:S:";

    while((o = getopt(argc, argv, optstirng)) != -1)	//设置参数
    {
        switch(o)
        {
            case 's':
                cout<<"[!]running with [sleep] function"<<endl;
                this->sleep = true;
                break;
            case 'c':
                cout<<"[!]running with [calculate] function"<<endl;
                this->calculate =true;
                break;
            case 'h':
                this->help = true;
                break;
            case 'H':
                this->Hour = stoi(optarg);
                break;
            case 'M':
                this->Minute = stoi(optarg);
                break;
            case 'S':
                this->Second = stoi(optarg);
                break;
            case '?':
                this->err = true;
                break;
        }

    }

}


bool cmdResolve::getsleep()
{
    return this->sleep;
}

bool cmdResolve::getcalculate()
{
    return this->calculate;
}

bool cmdResolve::gethelp()
{
    return this->help;
}

bool cmdResolve::geterr()
{
    return this->err;
}

int cmdResolve::getHour()
{
    return this->Hour;
}

int cmdResolve::getMinute()
{
    return this->Minute;
}

int cmdResolve::getSecond()
{
    return this->Second;
}



int main(int argc, char *argv[])
{
    int hour = 0, minute = 0, second = 0;


    cmdResolve cr;
    //设置参数
    cr.setPara(argc, argv);

    //判断需不需要help
    if(cr.geterr()) //有错误参数
    {
        cout<<"errors happening!!!"<<endl;
        help();
        return 0;
    }
    else if(cr.gethelp())       //请求帮助
    {
        help();
        return 0;
    }

    //没有错误或者help
    //设置时间
    hour = cr.getHour();
    minute = cr.getMinute();
    second = cr.getSecond();

    //Clock类实例化
    Clock t(hour, minute, second);

    //参数判断
    //-s睡眠方式
    if(cr.getsleep())
        t.run_through_sleep();

    //-c计算方式
    else if(cr.getcalculate())
        t.run_through_calculate();

    //没有参数的方式 默认为calculate方式
    else
    {
        //提示输入倒计时时间
        cout << "please input Clock: hour minute second" << endl;

        //获取倒计时时间
        cin>> hour >> minute >> second;

        //由于没有参数所以clock对象中时间为默认值（ 0 0 0）
        //所以在这一步设置时间
        t.set(hour, minute, second);

        t.run_through_calculate();
    }

    return 0;
}