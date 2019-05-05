# Live2d_cocos
cocos2dx 接入live2d
    local model = Live2DModel:create("Haru/Haru.model3.json")
    self:addChild(model)
    model:setPosition(cc.p(display.center))
    model:setScale(1)

    model:addClickTouchEvent( function(touch, eventType)
        local pos = touch:getLocationInView()
        local delta = touch:getDelta()

        if eventType == cc.EventCode.BEGAN then
            print("touch begin")
        elseif eventType == cc.EventCode.MOVED then
            print("touch move")
            -- model:setPosition(cc.p(model:getPositionX()+delta.x,model:getPositionY()+delta.y))
            model:OnDrag(pos.x, pos.y)
        elseif eventType == cc.EventCode.ENDED then
            print("touch ENDED")
            if model:HitTest("Body", pos.x, pos.y) then
                print("hit body")
                model:StartRandomMotion("TapBody", 3, function() print("ani is over") end)
            elseif model:HitTest("Head", pos.x, pos.y) then
                print("hit Head")
                model:SetRandomExpression()
            else
            end
        else
            print("touch CANCELLED")
        end
    end )
<a href="https://996.icu"><img src="https://img.shields.io/badge/link-996.icu-red.svg" alt="996.icu" /></a>
[![LICENSE](https://img.shields.io/badge/license-Anti%20996-blue.svg)](https://github.com/996icu/996.ICU/blob/master/LICENSE)
