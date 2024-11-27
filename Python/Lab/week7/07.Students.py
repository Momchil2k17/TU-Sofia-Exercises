students=(("Momchil Yankov",19,6,"Sofia"),("Kiril Evlogiev",21,5.4,"Pirdop"),
          ("Lom Velichkov",20,3.6,"Dolni Dubnik"),("Pencho Peev",22,4.78,"Gorna Orhqhovica"),
          ("Uti Bachvarov",51,3.24,"Gotveno"),("Ivan Zvezdev",29,4.09,"Kazichene"),
          ("Boiko Borisov",49,5.2,"Sofia"))


def good_students(students):
    grade=0
    for student in students:
        grade+=student[2]
    avgGrade=round(grade/7,2)
    print(avgGrade)
    goodStudents=[student[0] for student in students if student[2]>avgGrade]
    print(f"Студентите {", ".join(goodStudents)} се справят добре този семестър!")

good_students(students)