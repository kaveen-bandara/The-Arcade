#include <SFML/Graphics/CircleShape.hpp>

#include "../include/Game.hpp"

Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode({ 200, 200 }), "The Arcade", sf::Style::Close);
}

Game::~Game()
{
}

void Game::Run()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            while (auto event = m_context->m_window->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    m_context->m_window->close();
            }

            m_context->m_window->clear();
            m_context->m_window->draw(shape);
            m_context->m_window->display();
        }
    }
}