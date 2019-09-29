#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*请编写电视机类，电视机有开机和关机状态，有音量，有频道，
提供音量操作的方法，频道操作的方法。
由于电视机只能逐一调整频道，不能指定频道，增加遥控类，
遥控类除了拥有电视机已有的功能，再增加根据输入调台功能。
*/

class Television
{
	//友元类
	friend class Remote;
public:
	enum{on,off};//电视状态
	enum{ minVol,maxVol=100 };//音量从0到100
	enum{minChannel=1,maxChannel=255};//频道从1到255

	Television()
	{
		mState = off;
		mVolume = minVol;
		mChannel = minChannel;
	}
	//打开电视
	void OnOrOff()
	{
		this->mState = (this->mState == on ? off : on);
	}
	//调高音量
	void VolumeUp()
	{
		if (this->mVolume >= maxVol)
		{
			return;
		}

		this->mVolume++;
	}
	//调低音量
	void VolumeDown()
	{
		if (this->mVolume <= minVol)
		{
			return;
		}
		this->mVolume--;
	}
	//上调频道
	void ChannelUp()
	{
		if (mChannel >= maxChannel)
		{
			return;
		}
		this->mChannel++;
	}
	//下调频道
	void ChannelDown()
	{
		if (this->mChannel <= minChannel)
		{
			return;
		}
		this->mChannel--;
	}

	//展示当前电视状态信息
	void ShowTeleState()
	{
		cout << "开机状态" << (mState == on ? "以开机" : "已关机") << endl;
		if (mState == on)
		{
			cout << "当前音量:" << mVolume << endl;
			cout << "当前频道:" << mChannel << endl;
		}
		cout << "------------------" << endl;
	}

private:
	int mState;//电视机状态，开机还是关机
	int mVolume;//电视机音量
	int mChannel;//电视频道

};

//电视机调台只能一个一个的调，遥控可以指定频道
//电视遥控器


class Remote
{
public:
	Remote(Television*television)
	{
		pTelevision = television;
	}

public:
	//打开电视
	void OnOrOff()
	{
		pTelevision->OnOrOff();
	}

	//调高音量
	void VolumUp()
	{	
		pTelevision->VolumeUp();
	}

	//调低音量
	void VolumeDown()
	{
		pTelevision->VolumeDown();
	}

	//更换电视频道
	void ChannelUp()
	{
		pTelevision->ChannelUp();	
	}

	void ChannelDown()
	{
		pTelevision->ChannelDown();
	}

	//设置频道 遥控新增功能
	void SetChannel(int channel)
	{
		if (channel<Television::minChannel || channel>Television::maxChannel)
		{
			return;
		}
		pTelevision->mChannel = channel;
		//显示电视当前信息
	}
		void ShowTeleState()
		{
			pTelevision->ShowTeleState();
		}

private:
	Television*pTelevision;
};


void test()
{
	Television television;
	television.ShowTeleState();
	television.OnOrOff();
	television.VolumeUp();
	television.VolumeUp();
	television.VolumeUp();
	television.VolumeUp();
	television.VolumeUp();
	television.VolumeUp();
	television.ShowTeleState();

}

void test02()
{
	//创建电视
	Television television;
	Remote remote(&television);
	remote.OnOrOff();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.ChannelUp();
	remote.VolumUp();
	remote.VolumUp();
	remote.VolumUp();
	remote.VolumUp();
	remote.VolumUp();
	remote.ShowTeleState();
}



int main(){

	//test();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}