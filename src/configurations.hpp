#pragma once

namespace conf {
// Window configuration
    auto const window_size = sf::VideoMode(1280, 800);
    const sf::VideoMode monitor = sf::VideoMode::getDesktopMode();
    const sf::Vector2i monitor_center(static_cast<int>(monitor.width/2 - window_size.width/2),
                              static_cast<int>(monitor.height/2 - window_size.height/2));
    const sf::Vector2f window_center(static_cast<float>(window_size.width) / 2,
        static_cast<float>(window_size.height) / 2);
}

namespace consts
{
    constexpr int fps = 60;
    constexpr double dt = 1.0 / fps;
    constexpr double g = 9.81 * (dt * dt);
    const double l1 = 0.5;
    const double m1 = 0.05;
    const double l2 = 0.5;
    const double m2 = 0.05;
    const float scale = 400.0;
}