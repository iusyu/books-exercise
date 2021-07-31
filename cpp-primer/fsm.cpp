#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <assert.h>



class FSM {
public:
	FSM():state(State::Initial) {}

	enum class State{ Initial, HalfShaked, HandShaked, ReceivedBitfield, SendBitfield, Data, Closing};
	enum class PeerState { am_chocking, am_interested, peer_chocking, peer_interested};



	FSM& setState(State s) 
	{
		state = s;
		return *this;
	}

	FSM& update();
	FSM& runAway();
	FSM& findLeaf();
	FSM& goHome();

private:
	State state;

	struct cordinate {
		cordinate():x(0),y(0) {}
		cordinate(int xx, int yy): x(xx),y(yy) {}
		int x,y;
	} cordinate;
};

FSM& FSM::update() 
{
	switch(state){
		case State::Initial:
			goHome();
			break;
		case State::HandShaked:
			runAway();
			break;
		default:
			break;
	}
	return *this;
}

FSM& FSM::goHome()
{
	std::cout<<"GO HOME!!"<<std::endl;
	cordinate.x = 0;
	cordinate.y = 0;
	setState(State::HandShaked);
	return *this;
}

FSM& FSM::runAway()
{
	std::cout<<"MY POSITION X: "<<cordinate.x<< "  Y: "<<cordinate.y<<std::endl;
	cordinate.x+=5;
	cordinate.y+=10;
	std::cout<<"MY POSITION X: "<<cordinate.x<< "  Y: "<<cordinate.y<<std::endl;
	if( cordinate.x > 100 && cordinate.y >100)
		setState(State::Initial);
	return *this;
}

class Peer{
public:
	Peer();
	Peer(const Peer&);
	
	enum class State{ Initial, HalfShaked, HandShaked, ReceivedBitfield, SendBitfield, Data, Closing};
	enum class PeerState { am_chocking, am_interested, peer_chocking, peer_interested};

	int sock;
	char ip[16];
	unsigned short port;
	char id[21];

	State state;
	PeerState pstate;


};



int stop = 1;

void sig_handler(int sig)
{
	std::cout<<"I am leave!"<<std::endl;
	stop = 0;
}

int main(void)
{
	signal(SIGINT, sig_handler);
	FSM ant;
	while(stop) {
		ant.update();
		sleep(2);
	}

	assert(FSM::State::Initial == FSM::PeerState::am_chocking);
}

