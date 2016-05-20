/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef SCUMM_HE_MOONBASE_AI_DEFENCEUNIT_H
#define SCUMM_HE_MOONBASE_AI_DEFENCEUNIT_H

namespace Scumm {

enum {
	DUT_ANTI_AIR = 1,
	DUT_SHIELD = 2,
	DUT_MINE = 3,
	DUT_HUB = 4,
	DUT_TOWER = 5,
	DUT_BRIDGE = 6,
	DUT_ENERGY = 7,
	DUT_OFFENSE = 8,
	DUT_CRAWLER = 9
};

enum {
	DUS_ON = 1,
	DUS_OFF = 2,
	DUS_DESTROYED = 3
};

class DefenseUnit {
private:
	int m_ID;
	Common::Point m_pos;
	int m_distanceTo;
	int m_state;
	int m_radius;
	int m_armor;
	int m_cost;

public:
	DefenseUnit();
	DefenseUnit(DefenseUnit *inUnit);

	virtual ~DefenseUnit();

	void setID(int id) { m_ID = id; }
	void setDistanceTo(int distanceTo) { m_distanceTo = distanceTo; }
	void setState(int state) { m_state = state; }
	void setRadius(int radius) { m_radius = radius; }
	void setArmor(int armor) { m_armor = armor; }
	void setDamage(int damage) { m_armor -= damage; }
	void setPos(int x, int y) {
		m_pos.x = x;
		m_pos.y = y;
	}
	void setCost(int cost) { m_cost = cost; }

	int getID() const { return m_ID; }
	int getDistanceTo() const { return m_distanceTo; }
	int getState() const { return m_state; }
	int getRadius() const { return m_radius; }
	int getArmor() const { return m_armor; }
	int getPosX() const { return m_pos.x; }
	int getPosY() const { return m_pos.y; }
	int getCost() const { return m_cost; }

	virtual int getType() const = 0;

	virtual Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY) = 0;
	virtual int selectWeapon(int index) = 0;
};

class AntiAirUnit : public DefenseUnit {
private:

public:
	AntiAirUnit();
	AntiAirUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_ANTI_AIR; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class ShieldUnit : public DefenseUnit {
private:

public:
	ShieldUnit();
	ShieldUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_SHIELD; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class MineUnit : public DefenseUnit {
private:

public:
	MineUnit();
	MineUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_MINE; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class HubUnit : public DefenseUnit {
private:

public:
	HubUnit();
	HubUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_HUB; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class TowerUnit : public DefenseUnit {
private:

public:
	TowerUnit();
	TowerUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_TOWER; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class BridgeUnit : public DefenseUnit {
private:

public:
	BridgeUnit();
	BridgeUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_BRIDGE; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class EnergyUnit : public DefenseUnit {
private:

public:
	EnergyUnit();
	EnergyUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_ENERGY; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class OffenseUnit : public DefenseUnit {
private:

public:
	OffenseUnit();
	OffenseUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_OFFENSE; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

class CrawlerUnit : public DefenseUnit {
private:

public:
	CrawlerUnit();
	CrawlerUnit(DefenseUnit *inUnit);
	int getType() const { return DUT_CRAWLER; }
	Common::Point *createTargetPos(int index, int distance, int weaponType, int sourceX, int sourceY);
	int selectWeapon(int index);
};

} // End of namespace Scumm

#endif