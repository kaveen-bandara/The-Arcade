
#include "../include/AssetManager.hpp"

Engine::AssetManager::AssetManager()
{
}

Engine::AssetManager::~AssetManager()
{
}

void Engine::AssetManager::addTexture(int id, const std::string& filePath, bool wantrepeated)
{
	auto texture = std::make_unique<sf::Texture>();

	if (texture->loadFromFile(filePath))
	{
		texture->setRepeated(wantrepeated);
		m_textures[id] = std::move(texture);
	}
}

void Engine::AssetManager::addFont(int id, const std::string& filePath)
{
	auto font = std::make_unique<sf::Font>();

	if (font->openFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& Engine::AssetManager::getTexture(int id) const
{
	return *(m_textures.at(id).get());
}

const sf::Font& Engine::AssetManager::getFont(int id) const
{
	return *(m_fonts.at(id).get());
}