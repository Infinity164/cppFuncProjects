#include <iostream>
using namespace std;


class Device {
public:
	virtual bool isEnabled() = 0;
	virtual void enable() = 0;
	virtual void disable() = 0;
	virtual int getVolume() = 0;
	virtual void setVolume(int) = 0;
	virtual int getChannel() = 0;
	virtual void setChannel(int) = 0;
};

class Remote {
private:
	Device* device;
public:
	Remote(Device* device) : device(device){}
	void togglePower(){
		if (device->isEnabled() == 1) device->disable();
		else device->enable();
	}
	void VolumeDown(){
		int volume = device->getVolume();
		device->setVolume(volume--);
		cout << "Current volume is: " << volume << endl;
	}
	void VolumeUp(){
		int volume = device->getVolume();
		device->setVolume(volume++);
		cout << "Current volume is: " << volume << endl;
	}
	void ChannelMinus(){
		int channel = device->getChannel();
		device->setChannel(channel--);
		cout << "Current channel is: " << channel << endl;
	}
	void ChannelPlus(){
		int channel = device->getChannel();
		device->setChannel(channel++);
		cout << "Current channel is: " << channel << endl;
	}
};

class TV : public Device {
private:
	int volume = 0;
	int channel = 0;
	bool status = 0;
public:
	bool isEnabled() {
		return status;
	}
	void enable() {
		if (isEnabled()) {
			status = 1;
			cout << "TV is enabled!";
		}
		else return;
	}
	void disable() {
		if (!isEnabled()) {
			status = 0;
			cout << "TV is disabled!";
		}
		else return;
	}
	void setVolume(int vol) {
		volume = vol;
	}
	void setChannel(int chan) {
		channel = chan;
	}
	int getVolume() {
		return volume;
	}
	int getChannel() {
		return channel;
	}
};

class Radio : public Device {
private:
	int volume;
	int channel;
	bool status = 0;
public:
	bool isEnabled() {
		return status;
	}
	void enable() {
		if (isEnabled() == 0) {
			status = 1;
			cout << "Radio is enabled!";
		}
		else return;
	}
	void disable() {
		if (isEnabled() == 1) {
			status = 0;
			cout << "Radio is disabled!";
		}
		else return;
	}
	void setVolume(int vol) {
		volume = vol;
	}
	void setChannel(int chan) {
		channel = chan;
	}
	int getVolume() {
		return volume;
	}
	int getChannel() {
		return channel;
	}
};

int main()
{
	TV t;
	TV* tv1 = &t;
	Remote pult1(tv1);
	pult1.ChannelPlus();
	pult1.togglePower();
	pult1.togglePower();
}