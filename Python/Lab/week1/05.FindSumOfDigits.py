num=int(input("Num = "))
desetohilqdni= num//10000
num=num%10000
hilqdni=num//1000
num=num%1000
stotici=num//100
num=num%100
desetici=num//10
num=num%10
edinici=num
print(f"{desetohilqdni} {hilqdni} {stotici} {desetici} {edinici}")
print(f"{desetohilqdni*hilqdni*stotici*desetici*edinici}")