import time

print('=========== Welcome to Underground! ============')
print('''
     ,            _..._            ,
    {'.         .'     '.         .'}
    { ~ '.      _|=    __|_      .'  ~}
  { ~  ~ '-._ (___________) _.-'~  ~  }
 {~  ~  ~   ~.'           '. ~    ~    }
{  ~   ~  ~ /   /\     /\   \   ~    ~  }
{   ~   ~  /    __     __    \ ~   ~    }
 {   ~  /\/  -<( o)   ( o)>-  \/\ ~   ~}
  { ~   ;(      \/ .-. \/      );   ~ }
   { ~ ~\_  ()  ^ (   ) ^  ()  _/ ~  }
    '-._~ \   (`-._'-'_.-')   / ~_.-'
        '--\   `'._'+'_.'`   /--'
            \     \`-'/     /
             `\    '-'    /'
               `\       /'
                 '-...-' 
''')

hp = 0
att = 0
defend = 0
monsterLevel = 0

job = input('''Select Your Job(a or b)：
            A:Warrior
            B:Magic
            '''
           )
while (job != "a" and job != "A" and job != "b" and job != "B"):
    print("Input Error，Please input a or b")
    job = input('''Select Your Job：
            A：Warrior
            B：Magic
            ''')

level = int(input('Select Your Level：') )
monsterLevel = int(input('Select Enemy Level：') )             
             
if job == "a" or job == "A":
    hp = 800 + level * 59
    att = 100 + level * 10
    defend = 20 + level * 5


if job == "b" or job == "B":
    hp = 500 + level * 35
    att = 120 + level * 19
    defend = 15 + level * 3
        
print('You Level is 是{},Attack{},Hp{},Defence{}' .format(level, att, hp,defend))
print("=========== Fight began ==============")
bosshp = 10000 + monsterLevel*30
bossatt = 50 + monsterLevel * 8
bossdef = 50

while bosshp >= 0 and hp >= 0:
    hp = hp - bossatt
    print("\33[41mBoss\33[0m attack \33[42myou\33[0m!，HP - {}，HP remain：{}".format(bossatt, hp))
    bosshp = bosshp - att;
    print("\33[42mYou\33[0m attack \33[41mBoss\33[0m，Hit {} ，remain HP：{}".format(att,bosshp))
    print("==================================")
    
    time.sleep(0.5)
    
    if hp <= 0:
        print("You lose ，Try again! (Maybe you should improve your level")
    if bosshp <= 0:
        print("You Win!And Got a sword!")
        print('''
           ,
          / \\
         {   }
         !   !
         ; : ;
         | : |
         | : |
         l ; l
         l ; l
         I ; I
         I ; I
         I ; I
         I ; I
         d | b 
         H | H
         H | H
         H I H
 ,;,     H I H     ,;,
;H@H;    ;_H_;,   ;H@H;
`\Y/d_,;|4H@HK|;,_b\Y/'
 '\;MMMMM$@@@$MMMMM;/'
   ~~~*; !8@8!; *~~~
         ;888;
         ;888;
         ;888;
         ;888;
         d8@8b
         O8@8O
         T808T
          `~` 
''')
