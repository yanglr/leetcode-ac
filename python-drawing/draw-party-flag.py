#-*-coding:utf-8-*-
#导入模块，初始化屏幕
import turtle as t
screen = t.Screen()
screen.title("极客中心")
screen.bgcolor('white')
screen.setup(800,600)
screen.tracer()
 
#cpc党旗的类
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
    #实例化党旗对象，参数：x坐标、y坐标、缩放系数
    partyFlag = PartyFlag(20,140,1)
    #调用党旗对象的主要绘画方法
    partyFlag.draw()
    #循环屏幕上的内容
    screen.mainloop()