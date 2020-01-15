# Space Invaders [![Build Status](https://travis-ci.com/arnodeceuninck/SpaceInvaders.svg?token=TnFLkshybHQyJaSec7Hp&branch=master)](https://travis-ci.com/arnodeceuninck/SpaceInvaders)
A space shooting game made by Arno Deceuninck for the advanced programming course of the University of Antwerp.
## Compiling & Running
    ./run.sh
## Gameplay
Help! Aliens are invading the earth. They've already destroyed the whole space army, except you. You are our last hope. Destroy the aliens, before they get to close to the earth, or they will destroy you.
### Enemies
Enemies are smart. Most of the times they come in group, so be prepared. You can kill most off them with one shot, but be careful for the boss enemies, since they require three hits before they're killed. Enemies don't want to kill other enemies, so only enemies on the first row will shoot bullets.
### Controls
There are multiple controls implemented, use the one you like. You can't go out of the view. 
#### Left
For going left, you can use the keys 'A' or the left arrow.
#### Right
For going right, you can use the keys 'D' or the right arrow.
#### Fire
For firing a bullet, you can press the spacebar, 'S', 'W', arrow up or arrow down. Be cautious when firing: After shooting a bullet, your turret gets way to hot and needs to cooldown for some time. Still want to shoot more? Try changing the player.json file, but be careful you don't destroy your own bullets by shooting them too fast after each other.
## Goal
You've won a level when you've killed all enemies. Note: You can only be shot once. Want more lives? See hacks. You're lives reset after each level.  Be careful: You can also die. This can happen when an enemy shoots at you, or when you collide with an enemy, or when an enemy comes to close to earth. When you die, you're lives will be reset, and the enemies of the current level that you've already killed get respawned.
## Hacks
Is the game too easy for you? Or maybe too hard? Or do you want to modify a level, or create one yourself? Then this is the place to be.
### Entities
All files with data about the different entities (e.g. player.json, enemy.json, boss.json and bullet.json) are situated in the levels folder. They've a lot of common attributes. The most intersting for you are probably speed, which is the speed at which the entity can move, health, bullet, which is the json file where the information about the bullet it shoots is stored, sprite, which is the file of the sprite and timebetweenfire, which is the minimum amount of seconds between fire.
### Levels
The order of all levels and the background is described in levels.json. Each levels/file entry is the name of a json file which points to the layout of the level. Each level layout consists of the json file in which the player is described and a list of enemies with the files that describe them and their position in the game world.
## References
As almost every developer, I often require some help from the internet. All the sprite files are also found on the internet (and sometimes edited a little bit), so I would like to give a specials thanks to all the sites which helped me.
1. Daneels, G. (s.d.). *C++ lab sessions*. Visited on December 14, 2019 via https://student.idlab.uantwerpen.be/~gdaneels/gev_prog_site/index.html.
1. Stroustrup, B. (2013). *The C++ Programming Language*. Fourth Edition, published by Pearson Education, Inc.
1. Rouwe, J. (2005). *The Guerrilla Guide to Game Code*. Visited on December 14, 2019 via https://www.gamasutra.com/view/feature/2280/the_guerrilla_guide_to_game_code.php.
1. s.n. (2019). *Model-view-controller*. Visited on December 14, 2019 via https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller.
1. s.n. (2019). *Singleton pattern*. Visited on December 14, 2019 via https://en.wikipedia.org/wiki/Singleton_pattern.
1. Adams, E. (2009). *Fundamentals of Game Design: Game Worlds*. Visited on December 14, 2019 via http://www.peachpit.com/articles/article.aspx?p=1398008.
1. Vogel, E. (2013). *The Observer Pattern in .NET*. Visited on December 14, 2019 via https://visualstudiomagazine.com/articles/2013/08/14/the-observer-pattern-in-net.aspx.
1. Mi-K (2018). *C++ - Design pattern - Observer*. Visited on December 14, 2019 via https://www.badprog.com/c-design-pattern-observer.
1. Zirk (2017). *Re: [TravisCI] SFML is not up to date*. Visited on December 14, 2019 via https://en.sfml-dev.org/forums/index.php?topic=22103.0.
1. Nystrom, R. (2014). *Observer*. Visited on December 14, 2019 via https://gameprogrammingpatterns.com/observer.html.
1. Rogue Wave Software (s.d.). *The MVC Design Pattern*. Visited on December 14, 2019 via https://docs.roguewave.com/stingray/11.2/html/sflug/8-2.html.
1. s.n. (2019). *Date and time utilities*. Visited on December 15, 2019 via https://en.cppreference.com/w/cpp/chrono. 
1. s.n. (2019). *std::make_shared*. Visited on December 15, 2019 via http://www.cplusplus.com/reference/memory/make_shared/.
1. Gomila, L. (s.d.). *Sprites and textures*. Visited on December 15, 2019 via https://www.sfml-dev.org/tutorials/2.4/graphics-sprite.php.
1. Nicole (2014). *Here's my collection of pixel backgrounds tile*. Visited on December 15, 2019 via https://tenshiikisu.tumblr.com/post/79015021080/heres-my-collection-of-pixel-backgrounds-tile. 
1. Hapax (2014). *Re: Infinitely repeated tile as background sprite*. Visited on December 15, 2019 via https://en.sfml-dev.org/forums/index.php?topic=14382.0.
1. s.n. (2019). *std::weak_ptr*. Visited on December 19, 2019 via https://en.cppreference.com/w/cpp/memory/weak_ptr. 
1. Kilochek, Y. (2012). *std::shared_ptr of this*. Visited on December 19, 2019 via https://stackoverflow.com/questions/11711034/stdshared-ptr-of-this. 
1. Dave, s. (2011). *Can't downcast because class is not polymorphic?*. Visited on December 22, 2019 via https://stackoverflow.com/questions/8469900/cant-downcast-because-class-is-not-polymorphic.
1. Zozulinskyi (2019). *Space background, night sky and stars*. Visited on December 22, 2019 via https://365psd.com/istock/space-background-night-sky-and-stars-998878.
1. Sehe (2014). *shared_from_this causing bad_weak_ptr*. Visited on December 24, 2019 via https://stackoverflow.com/questions/27697973/shared-from-this-causing-bad-weak-ptr. 
1. Gomila, L. (s.d.). *https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php*. Visited on December 24, 2019 via https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php.
1. s.n. (2019). *std::exception*. Visited on December 24, 2019 via http://www.cplusplus.com/reference/exception/exception/.
1. s.n. (2019). *std::ios_base::failure*. Visited on December 24, 2019 via http://www.cplusplus.com/reference/ios/ios_base/failure/.
1. Yates, T. (2010). *https://stackoverflow.com/questions/3863567/in-c-check-if-two-instances-of-a-base-class-are-infact-of-the-same-subclass*. Visited on December 24, 2019 via https://stackoverflow.com/questions/3863567/in-c-check-if-two-instances-of-a-base-class-are-infact-of-the-same-subclass.
1. XtremeJ (2017). *A Space Overflight*. Visited on December 24, 2019 via https://www.pixilart.com/art/a-space-overflight-28a1440957594b9.
1. Houx, P. (2015). *[Solution] Calling shared_from_this() in the constructor.*. Visited on December 27, 2019 via https://forum.libcinder.org/topic/solution-calling-shared-from-this-in-the-constructor.
1. Willman, J. (2018). *laser_purple.png*. Visited on December 27, 2019 via http://redhulimachinelearning.com/wp-content/uploads/2018/11/laser_purple.png.
1. Dibling, J. (2013). *modulus is not working when using doubles in c++ [duplicate]*. Visited on December 28, 2019 via https://stackoverflow.com/questions/19503083/modulus-is-not-working-when-using-doubles-in-c.
1. Adams, V. (s.d.). *Seymour One*. Visited on December 28, 2019 via https://fonts.google.com/specimen/Seymour+One.
1. Gomila, L. (s.d.). *Texts and fonts*. Visited on December 28, 2019 via https://www.sfml-dev.org/tutorials/2.5/graphics-text.php. 
1. York, M. (2009). *C++ Singleton design pattern*. Visited on December 28, 2019 via https://stackoverflow.com/questions/1008019/c-singleton-design-pattern. 
1. s.n. (2018). *LaTeX/Title Creation*. Visited on January 7, 2020 via https://en.wikibooks.org/wiki/LaTeX/Title_Creation.

## Have fun playing ヽ(•‿•)ノ

