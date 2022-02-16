#pragma once
namespace TD
{


	enum class BulletType
	{
		NORMAL = 0,
		EXPLOSIVE = 1,
		STUN = 2
	};

	class ConfigTower
	{
	public:
		float FiringRate;
		unsigned int Damage;
		float Range;
		BulletType Bullet;
		unsigned int MaxLevel;

		ConfigTower(unsigned int en_type);
		ConfigTower()
		{
			this->Damage = 0;
			this->FiringRate = 0;
			this->MaxLevel = 0;
			this->Range = 0;
		};
	};
}