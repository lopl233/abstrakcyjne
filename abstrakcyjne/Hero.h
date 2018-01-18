#pragma once
class Hero
{
public:
	virtual int getMAX_HP() = 0;
	virtual void setMAX_HP(int MAX_HP) = 0;
	virtual int getCURRENT_HP() = 0;
	virtual void setCURRENT_HP(int CURRENT_HP) = 0;
	virtual int getMAX_MP() = 0;
	virtual void setMAX_MP(int MAX_MP) = 0;
	virtual int getCURRENT_MP() = 0;
	virtual void setCURRENT_MP(int CURRENT_MP) = 0;
	virtual void addHP(int val) = 0;
	virtual void addMP(int val) = 0;
	virtual void setId(int id) = 0;
};