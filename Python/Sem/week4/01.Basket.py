def FindDayWinner(winners):
    winTeams=winners.split()
    team1Count=0
    team2Count=0
    for team in winTeams:
        if(team=="Team1"):
            team1Count+=1
        elif(team=="Team2"):
            team2Count+=1
    if(team1Count>team2Count):
        return "Team1"
    elif(team1Count<team2Count):
        return "Team2"
    else:
        return "Tie"

winner=FindDayWinner("Team1 Team2 Team1 Team2 Team2")
print(winner)