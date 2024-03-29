/*
 * inputMgr.h
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 *
 *      Used by: Stefan Stukelja and Alex Crupi
 *      For: CS 381 - Assignment 4
 */

#ifndef INPUTMGR_H_
#define INPUTMGR_H_

#include <OgreWindowEventUtilities.h>
#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <mgr.h>

class InputMgr : public Mgr, public OIS::KeyListener, public OIS::MouseListener, public Ogre::WindowEventListener
{
private:
	void UpdateCamera(float dt);
	void UpdateDesiredSpeedHeading(float dt);
	void UpdateSelection(float dt);
	float keyboardTimer;
	float selectionTimer;
	const float keyTime = 0.2f;
	const float selectionTime = 0.2f;

protected:
	virtual void windowResized(Ogre::RenderWindow *rw);
	virtual void windowClosed(Ogre::RenderWindow *rw);

    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);
    virtual bool mouseMoved(const OIS::MouseEvent &arg);
    virtual bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
    virtual bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

public:

	InputMgr(Engine *engine);
	~InputMgr();
	virtual void init();
	virtual void tick(float dt);
	virtual void loadLevel();
	virtual void stop();

	//OIS Input devices
	OIS::InputManager* oisInputManager;
    OIS::Mouse*        mouse;
    OIS::Keyboard*     keyboard;
    bool cameraView = false;
};

#endif /* INPUTMGR_H_ */
