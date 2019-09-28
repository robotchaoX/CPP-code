#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*���д���ӻ��࣬���ӻ��п����͹ػ�״̬������������Ƶ����
�ṩ���������ķ�����Ƶ�������ķ�����
���ڵ��ӻ�ֻ����һ����Ƶ��������ָ��Ƶ��������ң���࣬
ң�������ӵ�е��ӻ����еĹ��ܣ������Ӹ��������̨���ܡ�
*/

class Television
{
	//��Ԫ��
	friend class Remote;
public:
	enum{on,off};//����״̬
	enum{ minVol,maxVol=100 };//������0��100
	enum{minChannel=1,maxChannel=255};//Ƶ����1��255

	Television()
	{
		mState = off;
		mVolume = minVol;
		mChannel = minChannel;
	}
	//�򿪵���
	void OnOrOff()
	{
		this->mState = (this->mState == on ? off : on);
	}
	//��������
	void VolumeUp()
	{
		if (this->mVolume >= maxVol)
		{
			return;
		}

		this->mVolume++;
	}
	//��������
	void VolumeDown()
	{
		if (this->mVolume <= minVol)
		{
			return;
		}
		this->mVolume--;
	}
	//�ϵ�Ƶ��
	void ChannelUp()
	{
		if (mChannel >= maxChannel)
		{
			return;
		}
		this->mChannel++;
	}
	//�µ�Ƶ��
	void ChannelDown()
	{
		if (this->mChannel <= minChannel)
		{
			return;
		}
		this->mChannel--;
	}

	//չʾ��ǰ����״̬��Ϣ
	void ShowTeleState()
	{
		cout << "����״̬" << (mState == on ? "�Կ���" : "�ѹػ�") << endl;
		if (mState == on)
		{
			cout << "��ǰ����:" << mVolume << endl;
			cout << "��ǰƵ��:" << mChannel << endl;
		}
		cout << "------------------" << endl;
	}

private:
	int mState;//���ӻ�״̬���������ǹػ�
	int mVolume;//���ӻ�����
	int mChannel;//����Ƶ��

};

//���ӻ���ֻ̨��һ��һ���ĵ���ң�ؿ���ָ��Ƶ��
//����ң����


class Remote
{
public:
	Remote(Television*television)
	{
		pTelevision = television;
	}

public:
	//�򿪵���
	void OnOrOff()
	{
		pTelevision->OnOrOff();
	}

	//��������
	void VolumUp()
	{	
		pTelevision->VolumeUp();
	}

	//��������
	void VolumeDown()
	{
		pTelevision->VolumeDown();
	}

	//��������Ƶ��
	void ChannelUp()
	{
		pTelevision->ChannelUp();	
	}

	void ChannelDown()
	{
		pTelevision->ChannelDown();
	}

	//����Ƶ�� ң����������
	void SetChannel(int channel)
	{
		if (channel<Television::minChannel || channel>Television::maxChannel)
		{
			return;
		}
		pTelevision->mChannel = channel;
		//��ʾ���ӵ�ǰ��Ϣ
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
	//��������
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