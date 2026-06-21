#pragma once 

#include "object_screen.h"

class ObjectWorld : public ObjectScreen
{
protected:
    glm::vec2 position_ = glm::vec2(0,0);
    glm::vec2 render_position;
public:
    ObjectWorld()=default;
    virtual ~ObjectWorld()=default;
    virtual void update(float dt) override;

    glm::vec2 getPosition() const { return position_; }
    void setPosition(const glm::vec2 &position);
    virtual void setRenderPosition(const glm::vec2 &render_position) override;

};

