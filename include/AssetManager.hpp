
#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
	class AssetManager
	{
	private:
		std::map<int, std::unique_ptr<sf::Texture>> m_textures;
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;

	public:
		AssetManager();
		~AssetManager();

		void addTexture(int id, const std::string& filePath, bool wantrepeated = false);
		void addFont(int id, const std::string& filePath);

		const sf::Texture& getTexture(int id) const;
		const sf::Font& getFont(int id) const;
	};
}

