#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "events.hpp"
#include "configurations.hpp"
#include <typeinfo>
#include "physics.hpp"

int main() {
    sf::RenderWindow window(conf::window_size, "Double Pendulum");

    window.setPosition(conf::monitor_center);
    window.setMouseCursorVisible(false);

    double theta1 = std::numbers::pi;
    double theta_vel1 = 0.0;
    double theta2 = std::numbers::pi + 0.2;
    double theta_vel2 = 0.0;
    double accumulator = 0.0;
    sf::Clock clock;

    while (window.isOpen())
    {
        processEvents(window);

        // Physics stuff
        double frame_duration = clock.restart().asSeconds();
        accumulator += frame_duration;
        auto num_ticks = static_cast<int>(floor(accumulator / consts::dt));
        accumulator -= static_cast<double>(num_ticks) * consts::dt;


        for (int tick_index = 0; tick_index < num_ticks; ++tick_index)
        {
            auto acc = computeImplicitEuler(consts::g, consts::m1, consts::m2,
                consts::l1, consts::l2, theta1, theta2, theta_vel1, theta_vel2, consts::dt);
            theta_vel1 += get<0>(acc);
            theta_vel2 += get<1>(acc);
            theta1 += theta_vel1;
            theta2 += theta_vel2;
        }

        window.clear(sf::Color::Black);

        sf::Vertex vertices[3];

        sf::Vector2f point1(conf::window_center.x, conf::window_center.y);
        auto point2 = point1
            + sf::Vector2f(static_cast<float>(consts::scale * consts::l1 * sin(theta1)),
                           static_cast<float>(consts::scale * consts::l1 * cos(theta1)));
        auto point3 = point2
            + sf::Vector2f(static_cast<float>(consts::scale * consts::l1 * sin(theta2)),
                           static_cast<float>(consts::scale * consts::l1 * cos(theta2)));

        vertices[0] = point1;
        vertices[1] = point2;
        vertices[2] = point3;


        window.draw(vertices, 3, sf::LinesStrip);
        window.display();
    }

    return 0;
}
