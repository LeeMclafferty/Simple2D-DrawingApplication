#pragma once

#include <SFML/Graphics.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>

namespace cereal {

	// Serialize sf::Vector2f
	template <class Archive>
	void serialize(Archive& ar, sf::Vector2f& vector) {
		ar(CEREAL_NVP(vector.x), CEREAL_NVP(vector.y));
	}

	// Serialize sf::Color
	template <class Archive>
	void serialize(Archive& ar, sf::Color& color) {
		ar(CEREAL_NVP(color.r), CEREAL_NVP(color.g), CEREAL_NVP(color.b), CEREAL_NVP(color.a));
	}

	template <class Archive>
	void save(Archive& ar, const sf::RectangleShape& shape) {
		sf::Vector2f position = shape.getPosition();
		sf::Vector2f size = shape.getSize();
		sf::Color fillColor = shape.getFillColor();
		sf::Color outlineColor = shape.getOutlineColor();
		float outlineThickness = shape.getOutlineThickness();

		ar(CEREAL_NVP(position), CEREAL_NVP(size), CEREAL_NVP(fillColor), CEREAL_NVP(outlineColor), CEREAL_NVP(outlineThickness));
	}

	template <class Archive>
	void load(Archive& ar, sf::RectangleShape& shape) {
		sf::Vector2f position;
		sf::Vector2f size;
		sf::Color fillColor;
		sf::Color outlineColor;
		float outlineThickness;

		ar(CEREAL_NVP(position), CEREAL_NVP(size), CEREAL_NVP(fillColor), CEREAL_NVP(outlineColor), CEREAL_NVP(outlineThickness));

		shape.setPosition(position);
		shape.setSize(size);
		shape.setFillColor(fillColor);
		shape.setOutlineColor(outlineColor);
		shape.setOutlineThickness(outlineThickness);
	}

	template <class Archive>
	void save(Archive& ar, const sf::CircleShape& circle) {
		sf::Vector2f position = circle.getPosition();
		float radius = circle.getRadius();
		sf::Color fillColor = circle.getFillColor();
		sf::Color outlineColor = circle.getOutlineColor();
		float outlineThickness = circle.getOutlineThickness();

		ar(CEREAL_NVP(position), CEREAL_NVP(radius), CEREAL_NVP(fillColor), CEREAL_NVP(outlineColor), CEREAL_NVP(outlineThickness));
	}

	template <class Archive>
	void load(Archive& ar, sf::CircleShape& circle) {
		sf::Vector2f position;
		float radius;
		sf::Color fillColor;
		sf::Color outlineColor;
		float outlineThickness;

		ar(CEREAL_NVP(position), CEREAL_NVP(radius), CEREAL_NVP(fillColor), CEREAL_NVP(outlineColor), CEREAL_NVP(outlineThickness));

		circle.setPosition(position);
		circle.setRadius(radius);
		circle.setFillColor(fillColor);
		circle.setOutlineColor(outlineColor);
		circle.setOutlineThickness(outlineThickness);
	}
}
