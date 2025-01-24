import figures as f

figure=int(input("Choose a figure: 1.Triangle 2.Square 3.Rectangle 4.Trapezoid 5.Romb:"))

if (figure==1):
    f.triangle(input("a:"),input("b:"),input("c:"))
if (figure==2):
    f.square(input("a:"))
if (figure==3):
    f.rectangle(input("a:"),input("b:"))
if (figure==4):
    f.trapezoid(input("a:"),input("b:"),input("h:"))
if (figure==5):
    f.romb(input("a:"),input("h:"))

