import pygame
import math
import random
from pygame import mixer
#init pygame
pygame.init()

#init scrren
screen=pygame.display.set_mode((800,600))
background=pygame.image.load('background.png')

#background sound
mixer.music.load('background.wav')
mixer.music.play(-1)

#title and icon
pygame.display.set_caption('Space Invaders')
icon=pygame.image.load('rocket.png')
pygame.display.set_icon(icon)

#game loop
#player
playerimg=pygame.image.load('space-invaders.png')
playerx=370
playery=480
playerxchange=0

#enemy
enemyimg=[]
enemyx=[]
enemyy=[]
enemyxchange=[]
enemyychange=[]
numofenemies=6
for i in range(numofenemies):
    enemyimg.append(pygame.image.load('planet.png'))
    enemyx.append(random.randint(0,736))
    enemyy.append(random.randint(50,150))
    enemyxchange.append(3)
    enemyychange.append(40)

#bullet
bulletimg=pygame.image.load('bullet.png')
bulletx=0
bullety=480
bulletxchange=0
bulletychange=10
bulletstate='ready'

def player(x,y):
    screen.blit(playerimg,(x,y))

def enemy(x,y,i):
    screen.blit(enemyimg[i],(x,y))

def bullet(x,y):
    global bulletstate
    bulletstate='fire'
    screen.blit(bulletimg,(x+16,y+10))

def iscollision(enemyx,enemyy,bulletx,bullety):
    distance=math.sqrt(math.pow(enemyx -bulletx,2)+math.pow(enemyy-bullety,2))
    if distance<27:
        return True
    return False

#score
scorevalue=0
font=pygame.font.Font('freesansbold.ttf',32)
overfont=pygame.font.Font('freesansbold.ttf',64)
textx=10
texty=10

def showscore(x,y):
    score=font.render("Score:" + str(scorevalue),True,(255,255,255))
    screen.blit(score,(x,y))
def gameover():
    overscore=overfont.render("GAME OVER",True,(255,255,255))
    screen.blit(overscore,(200,250))

running =True
while running:
    screen.fill((0,0,0))
    screen.blit(background,(0,0))
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            running=False
        
        if event.type==pygame.KEYDOWN:
            if event.key==pygame.K_LEFT:
                playerxchange=-5
            if event.key==pygame.K_RIGHT:
                playerxchange=5
            if event.key==pygame.K_SPACE:
                if bulletstate=='ready':
                    bulletsound=mixer.Sound('laser.wav')
                    bulletsound.play()
                    bulletx=playerx
                    bullet(playerx,bullety)

        if event.type==pygame.KEYUP:
            if event.key==pygame.K_LEFT or event.key==pygame.K_RIGHT:
               playerxchange=0

    #checking for boundary   
    playerx+=playerxchange
    if playerx<=0:
        playerx=0
    elif playerx>=736:
        playerx=736

    #collsion
    #enemy movement
    for i in range(numofenemies):
        if enemyy[i]>440:
            for j in range(numofenemies):
                enemyy[j]=2000
            gameover()
            break
        enemyx[i]+=enemyxchange[i]
        if enemyx[i]<=0:
            enemyxchange[i]=3
            enemyy[i]+=enemyychange[i]
        elif enemyx[i]>=736:
            enemyxchange[i]=-3
            enemyy[i]+=enemyychange[i]

        collision=iscollision(enemyx[i],enemyy[i],bulletx,bullety)
        if collision:
            explosionsound=mixer.Sound('explosion.wav')
            explosionsound.play()
            bullety=480
            bulletstate='ready'
            scorevalue+=1
            enemyx[i]=random.randint(0,736)
            enemyy[i]=random.randint(50,150)
        enemy(enemyx[i],enemyy[i],i)
    
    if bullety<=0:
        bullety=480
        bulletstate='ready'

    if bulletstate is 'fire':
        bullet(bulletx,bullety)
        bullety-=bulletychange
   
    showscore(textx,texty)
    player(playerx,playery)
    pygame.display.update()
