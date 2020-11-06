#include "sfmlboxinstanceinfo.h"

#include "../../spriterengine/global/settings.h"

namespace SpriterEngine
{

	SfmlBoxInstanceInfo::SfmlBoxInstanceInfo(point initialSize, sf::RenderWindow *validRenderWindow) :
		BoxInstanceInfo(initialSize),
		renderWindow(validRenderWindow),
		rectangle(sf::Vector2f(static_cast<float>(initialSize.x), static_cast<float>(initialSize.y)))
	{
	}

	void SfmlBoxInstanceInfo::render()
	{
		if (Settings::renderDebugBoxes)
		{
			rectangle.setPosition(static_cast<float>(getPosition().x), static_cast<float>(getPosition().y));
			rectangle.setRotation(static_cast<float>(toDegrees(getAngle())));
			rectangle.setScale(static_cast<float>(getScale().x), static_cast<float>(getScale().y));
			rectangle.setOrigin(static_cast<float>(getPivot().x * getSize().x), static_cast<float>(getPivot().y * getSize().y));
			renderWindow->draw(rectangle);
		}
	}

}
