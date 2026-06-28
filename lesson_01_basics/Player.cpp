#include "Player.h"
#include <iostream>
#include <string>

const char* PlayerStateToString(PlayerState state)
{
	switch (state)
	{
	case PlayerState::Alive:
		return "Alive";
	case PlayerState::Dead:
		return "Dead";
	case PlayerState::Stunned:
		return "Stunned";
	default:
		return "Unknown";
	}
}

Player::Player(const std::string& nameConstruct) : name{ nameConstruct }, maxHealth{ DefaultMaxHealth }, health{ maxHealth }, level{ StartLevel }, maxExperience{ DefaultMaxExperience }, experience { StartExperience }, state{PlayerState::Alive}
{
	if (nameConstruct.empty() || nameConstruct.length() > MaxNameLength)
	{
		name = DefaultName;
	}
}

Player::~Player()
{
	std::cout << "Player " << name << " has been destroyed.\n";
}


void Player::PrintInfo() const
{
	std::cout << "Player Name: " << name << '\n';
	std::cout << "Health: " << health << "/" << maxHealth << '\n';
	std::cout << "Level: " << level << '\n';
	std::cout << "Experience Points: " << experience << "/" << maxExperience << '\n';
	std::cout << "State: " << PlayerStateToString(state) << '\n';
}

void Player::LevelUp()
{
	level += 1;
}

void Player::AddExperience(int pointsToAdd)
{
	if (pointsToAdd < MinAddedExperience || IsDead())
	{
		return;
	}
	else
	{
		experience += pointsToAdd;

		while (experience >= maxExperience)
		{
			experience -= maxExperience;
			LevelUp();
		}
	}
}

bool Player::IsDead() const
{
	return state == PlayerState::Dead;
}

void Player::TakeDamage(int damage)
{
	if (damage < MinDamage || IsDead())
	{
		return;
	}
	else
	{
		health -= damage;
		if (health <= MinHealth)
		{
			state = PlayerState::Dead;
			health = MinHealth;
		}
	}
}


void Player::Heal(int healAmount)
{
	if (IsDead() || healAmount < MinHeal)
	{
		return;
	}
	else
	{
		health += healAmount;

		if (health > maxHealth)
		{
			health = maxHealth;
		}
	}
}

const std::string& Player::GetName() const
{
	return name;
}

void Player::SetName(const std::string& newName)
{
	if (newName.empty() || newName.length() > MaxNameLength)
	{
		return;
	}
	else
	{
		name = newName;
	}
}

int Player::GetHealth() const
{
	return health;
}

int Player::GetLevel() const
{
	return level;
}

int Player::GetExperience() const
{
	return experience;
}

int Player::GetMaxHealth() const
{
	return maxHealth;
}

int Player::GetMaxExperience() const
{
	return maxExperience;
}

PlayerState Player::GetState() const
{
	return state;
}

