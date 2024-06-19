#include <iostream>
using namespace std;

class State {
public:
    virtual ~State() = default;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

class Musicplayer {
private:
    State* playingstate;
    State* stoppedstate;
    State* pausedstate;
    State* state;
public:
    Musicplayer();
    void setState(State* newstate) { state = newstate; }
    void play() { state->play(); };
    void pause() { state->pause(); };
    void stop() { state->stop(); };
    State* getStoppedState() { return stoppedstate; }
    State* getPausedState() { return pausedstate; }
    State* getPlayingState() { return playingstate; }
};




class PlayingState : public State {
private:
    Musicplayer* player;
public:
    PlayingState(Musicplayer* player) : player(player) {}
    void play() { cout << "Player already playing" << endl; }
    void pause() {
        cout << "Pausing player" << endl;
        player->setState(player->getPausedState());
    }
    void stop() {
        cout << "Stopping player" << endl;
        player->setState(player->getStoppedState());
    }
};

class PausedState : public State {
private:
    Musicplayer* player;
public:
    PausedState(Musicplayer* player) : player(player){}
    void play() {
        cout << "Starting playing" << endl;
        player->setState(player->getPlayingState());
    }
    void pause() { cout << "Player already paused" << endl; }
    void stop() {
        cout << "Stopping playing" << endl;
        player->setState(player->getStoppedState());
    }
};

class StoppedState : public State {
private:
    Musicplayer* player;
public:
    StoppedState(Musicplayer* player) : player(player) {}
    void play() {
        cout << "Starting playing" << endl;
        player->setState(player->getPlayingState());
    }
    void pause() { cout << "Can not pause stopped player" << endl; }
    void stop() { cout << "Player already stopped" << endl; }
};

Musicplayer::Musicplayer() {
    this->stoppedstate = new StoppedState(this);
    this->playingstate = new PlayingState(this);
    this->pausedstate = new PausedState(this);
    state = stoppedstate;
}

int main()
{
    Musicplayer player;
    player.play();
    player.play();
}