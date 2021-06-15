#-*-coding:utf-8-*-
#导入模块，初始化屏幕
import turtle as t
screen = t.Screen()
screen.title("极客中心")
screen.bgcolor('white')
screen.setup(800,600)
screen.tracer()
 
#小人类
class People(object):
    #小人的属性
    def __init__(self,x,y,extend):
        self.x = x
        self.y = y
        self.head = t.Turtle()
        self.eyes = t.Turtle()
        self.hands = t.Turtle()
        self.legs = t.Turtle()
        self.body = t.Turtle()
        self.text = t.Turtle()
        self.extend = extend
 
#画出头的函数
    def drawHead(self):
        self.head.pencolor("red")
        self.head.pensize(2)
        self.head.speed(100)
        self.head.up()
        self.head.goto(self.x, self.y)
        self.head.down()
        self.head.circle(50*self.extend, 360)
        self.head.hideturtle()
 
#画出眼睛的函数
    def drawEyes(self):
        eX = self.head.xcor()-20*self.extend
        eY = self.head.ycor()+70*self.extend
        self.eyes.pencolor("red")
        self.eyes.pensize(2)
        self.eyes.speed(100)
        self.eyes.up()
        self.eyes.goto(eX,eY)
        self.eyes.down()
        self.eyes.right(90)
        self.eyes.forward(40*self.extend)
        self.eyes.up()
        self.eyes.left(90)
        self.eyes.forward(40*self.extend)
        self.eyes.left(90)
        self.eyes.down()
        self.eyes.forward(40*self.extend)
        self.eyes.hideturtle()
 
#画出身体的函数
    def drawBody(self):
        bX = self.head.xcor()
        bY = self.head.ycor()
        self.body.pencolor("red")
        self.body.pensize(2)
        self.body.speed(100)
        self.body.up()
        self.body.goto(bX,bY)
        self.body.right(90)
        self.body.down()
        self.body.forward(100*self.extend)
        self.body.hideturtle()
 
#画出手的函数
    def drawHands(self):
        hX = self.head.xcor()
        hY = self.head.ycor()-30*self.extend
        self.hands.pencolor("red")
        self.hands.pensize(2)
        self.hands.speed(100)
        self.hands.up()
        self.hands.goto(hX,hY)
        self.hands.down()
        self.hands.forward(60*self.extend)
        self.hands.left(60)
        self.hands.forward(60*self.extend)
        self.hands.up()
        self.hands.goto(hX,hY-15*self.extend)
        self.hands.right(60)
        self.hands.down()
        self.hands.forward(60*self.extend)
        self.hands.right(60)
        self.hands.forward(60*self.extend)
        self.hands.hideturtle()
 
#画出腿的函数
    def drawLegs(self):
        dX = self.head.xcor()
        dY = self.head.ycor()-100*self.extend
        self.legs.pencolor("red")
        self.legs.pensize(2)
        self.legs.speed(100)
        self.legs.up()
        self.legs.goto(dX,dY)
        self.legs.down()
        self.legs.forward(60*self.extend)
        self.legs.right(120)
        self.legs.forward(60*self.extend)
        self.legs.up()
        self.legs.goto(dX,dY)
        self.legs.down()
        self.legs.forward(60*self.extend)
        self.legs.hideturtle()
 
#绘制文本的函数
    def drawText(self):
        tX = self.head.xcor()-50*self.extend
        tY = self.head.ycor()+130*self.extend
        self.text.up()
        self.text.pencolor("blue")
        self.text.goto(tX,tY)
        self.text.write("极客中心",align='left',font=('Arial',20*self.extend,"normal"))
        self.text.hideturtle()
 
#画出整个小人的函数入口
    def draw(self):
        self.drawHead()
        self.drawEyes()
        self.drawBody()
        self.drawHands()
        self.drawLegs()
        self.drawText()
 
#爱心的类
class Love(object):
    #初始化爱心的属性
    def __init__(self,x,y,extend):
        self.x = x
        self.y = y
        self.extend = extend
        self.love = t.Turtle()
 
#画出爱心以及文字的函数
    def draw(self):
        self.love.up()
        self.love.goto(self.x,self.y)
        self.love.pensize(2)
        self.love.pencolor("red")
        self.love.speed(100)
        self.love.fillcolor("pink")
        self.love.begin_fill()
        self.love.down()
        self.love.left(90)
        self.love.circle(26*self.extend,180)
        self.love.circle(75*self.extend,72)
        self.love.left(36)
        self.love.circle(75*self.extend,72)
        self.love.circle(26*self.extend,180)
        self.love.end_fill()
        self.love.up()
        self.love.forward(120*self.extend)
        self.love.right(90)
        self.love.forward(60*self.extend)
        self.love.write("To: 伟大的中国共产党",align='left',font=('Arial',10*self.extend,"normal"))
        self.love.hideturtle()
 
#党旗的类
class PartyFlag(object):
    #初始化党旗属性
    def __init__(self,x,y,extend):
        self.x = x
        self.y = y
        self.extend = extend
        self.frame = t.Turtle()
        self.sickle = t.Turtle()
        self.ax = t.Turtle()
 
#画出党旗面的方法
    def drawFrame(self):
        self.frame.up()
        self.frame.goto(self.x,self.y)
        self.frame.pencolor("red")
        self.frame.shapesize(2)
        self.frame.speed(100)
        self.frame.fillcolor("red")
        self.frame.begin_fill()
        self.frame.down()
        self.frame.forward(300*self.extend)
        self.frame.right(90)
        self.frame.forward(200*self.extend)
        self.frame.right(90)
        self.frame.forward(300*self.extend)
        self.frame.right(90)
        self.frame.forward(200*self.extend)
        self.frame.end_fill()
        self.frame.hideturtle()
 
#画出斧头的函数
    def drawAx(self):
        aX = self.frame.xcor()+25*self.extend
        aY = self.frame.ycor()-45*self.extend
        self.ax.up()
        self.ax.goto(aX,aY)
        self.ax.pencolor("yellow")
        self.ax.pensize(2)
        self.ax.speed(100)
        self.ax.down()
        self.ax.left(45)
        self.ax.fillcolor("yellow")
        self.ax.begin_fill()
        self.ax.forward(30*self.extend)
        self.ax.right(90)
        self.ax.circle(10*self.extend,90)
        self.ax.right(90)
        self.ax.forward(10*self.extend)
        self.ax.right(90)
        self.ax.forward(15*self.extend)
        self.ax.left(90)
        self.ax.forward(70*self.extend)
        self.ax.right(90)
        self.ax.forward(15*self.extend)
        self.ax.right(90)
        self.ax.forward(70*self.extend)
        self.ax.left(90)
        self.ax.forward(10*self.extend)
        self.ax.right(90)
        self.ax.forward(20*self.extend)
        self.ax.end_fill()
        self.ax.hideturtle()
 
#画出镰刀的函数
    def drawSickle(self):
        sX = self.frame.xcor()+30*self.extend
        sY = self.frame.ycor()-69*self.extend
        self.sickle.up()
        self.sickle.goto(sX,sY)
        self.sickle.pencolor("yellow")
        self.sickle.pensize(2)
        self.sickle.speed(100)
        self.sickle.fillcolor("yellow")
        self.sickle.begin_fill()
        self.sickle.right(45)
        self.sickle.down()
        self.sickle.circle(40*self.extend,90)
        self.sickle.left(25)
        self.sickle.circle(45*self.extend,90)
        self.sickle.right(160)
        self.sickle.circle(-45*self.extend,130)
        self.sickle.right(10)
        self.sickle.circle(-48*self.extend,75)
        self.sickle.left(160)
        self.sickle.circle(-7*self.extend,340)
        self.sickle.left(180)
        self.sickle.circle(-48*self.extend,15)
        self.sickle.right(75)
        self.sickle.forward(11*self.extend)
        self.sickle.end_fill()
        self.sickle.hideturtle()
 
#画出整个党旗的函数入口
    def draw(self):
        self.drawFrame()
        self.drawAx()
        self.drawSickle()
 
#整个程序的入口
if __name__ == '__main__':
    #实例化小人、爱心、党旗对象，参数：x坐标、y坐标、缩放系数
    people = People(-300,70,1)
    love = Love(-100,55,1)
    partyFlag = PartyFlag(20,140,1)
    #调用各对象的主要绘画方法
    people.draw()
    love.draw()
    partyFlag.draw()
    #循环屏幕上的内容
    screen.mainloop()