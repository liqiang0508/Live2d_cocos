
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    -- add background image
    display.newSprite("HelloWorld.png")
        :move(display.center)
        :addTo(self)

    local model = Live2DModel:create("live2d30/live2d30.model3.json")
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
                    model:StartMotion("Poker", 0,3, function()
                         print("end**")
                   end,true)
            if model:HitTest("Body", pos.x, pos.y) then
                print("hit body")
               -- model:StartRandomMotion("TapBody", 3, function() print("ani is over") end)
            elseif model:HitTest("Head", pos.x, pos.y) then
                print("hit Head")
                --model:SetRandomExpression()
            else
            end
        else
            print("touch CANCELLED")
        end
    end )

     model:StartMotion("Idle", 0, 1, function()
                         print("idle end**")
                   end,true)
  print("222222111111")
  

end

return MainScene
