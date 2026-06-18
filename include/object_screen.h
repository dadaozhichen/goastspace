#pragma once 
#include "object.h"

class ObjectScreen:public Object
{

protected:
    glm::vec2 render_position_ = glm::vec2(0,0);


public:
    ObjectScreen()=default;
    virtual ~ObjectScreen()=default;
    glm::vec2 fetRenderPosition() const {return render_position_;}
    virtual void setRenderPosition(const glm::vec2 &render_position) {render_position_ = render_position;}

};


