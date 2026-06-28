#pragma once
#include <string>

enum class PlayerState
{
	Alive,
	Dead,
	Stunned,
};

class Player
{
private:
	std::string name{};
	int maxHealth;
	int health;
	int level;
	int maxExperience;
	int experience;
	PlayerState state;

	static constexpr int MinHealth = 0;
	static constexpr int StartExperience = 0;
	static constexpr int DefaultMaxExperience = 100;
	static constexpr int MinDamage = 1;
	static constexpr int MinAddedExperience = 1;
	static constexpr int MinHeal = 1;
	static constexpr int StartLevel = 1;
	static constexpr int MaxNameLength = 20;
	static constexpr int DefaultMaxHealth = 100;
	static constexpr const char* DefaultName = "DefaultName";

	void LevelUp();
public:
	Player(const std::string& nameConstruct);
	~Player();
	void PrintInfo() const;
	void AddExperience(int pointsToAdd);
	bool IsDead() const;
	void TakeDamage(int damage);
	void Heal(int healAmount);

	const std::string& GetName() const;
	int GetHealth() const;
	int GetLevel() const;
	int GetExperience() const;
	int GetMaxHealth() const;
	int GetMaxExperience() const;
	PlayerState GetState() const;

	void SetName(const std::string& newName);
};