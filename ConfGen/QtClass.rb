#!/usr/bin/ruby
# -*- coding: utf-8 -*-
=begin
# QtClass.rb for  in /home/lund/Projets/zappy-poney/ConfGen
# 
# Made by florian dewulf
# Login   <dewulf_f@epitech.net>
# 
# Started on  Mon Jun 10 18:25:16 2013 florian dewulf
# Last update Tue Jun 11 16:14:29 2013 florian dewulf
=end

require 'Qt'

class   QtApp < Qt::Widget
#Slots Qt Define
  slots 'launch_script()'

#Constructor
  def   initialize
    super                                       #call the QtWidget Constructor
    setWindowTitle("Generateur de fichier de conf zappy")     #name the window
    init_ui                                     #call my creation window function
    setFixedSize(650, 300)                      #set the size of the window
    move(300, 300)                              #move the window
    show                                        #show the window
  end

  def   init_ui
    #creation and initialisation of my Widgets
    quit = Qt::Action.new("&Quit", self)
    welcome = Qt::Label.new('Bienvenue dans le générateur de fichier de conf Zappy', self)
    welcome.setAlignment(Qt::AlignHCenter.to_i | Qt::AlignTop.to_i)
    repopnourriture = Qt::Label.new('Temps de repop nourriture', self)
    repoplinemate = Qt::Label.new('Temps de repop de la linemate', self)
    repopderaumere = Qt::Label.new('Temps de repop de la deraume', self)
    repopsibur = Qt::Label.new('Temps de repop de la sibur', self)
    repopmendiane = Qt::Label.new('Temps de repop de la mendiane', self)
    repopphiras = Qt::Label.new('Temps de repop de la phiras', self)
    repopthystame = Qt::Label.new('Temps de repop de la thystame', self)
    maxnourriture = Qt::Label.new('Valeur max de nourriture', self)
    maxlinemate = Qt::Label.new('Valeur max de la linemate', self)
    maxderaumere = Qt::Label.new('Valeur max de laraume', self)
    maxsibur = Qt::Label.new('Valeur max de la sibur', self)
    maxmendiane = Qt::Label.new('Valeur max de la mendiane', self)
    maxphiras = Qt::Label.new('Valeur max de la phiras', self)
    maxthystame = Qt::Label.new('Valeur max de la thystame', self)
    savefile = Qt::Label.new('Emplacement du fichier de sauvegarde', self)
    @popnourriture = Qt::SpinBox.new(self)
    @poplinemate = Qt::SpinBox.new(self)
    @popderaumere = Qt::SpinBox.new(self)
    @popsibur = Qt::SpinBox.new(self)
    @popmendiane = Qt::SpinBox.new(self)
    @popphiras = Qt::SpinBox.new(self)
    @popthystame = Qt::SpinBox.new(self)
    @maxnourriture = Qt::SpinBox.new(self)
    @maxlinemate = Qt::SpinBox.new(self)
    @maxderaumere = Qt::SpinBox.new(self)
    @maxsibur = Qt::SpinBox.new(self)
    @maxmendiane = Qt::SpinBox.new(self)
    @maxphiras = Qt::SpinBox.new(self)
    @maxthystame = Qt::SpinBox.new(self)
    @input_save = Qt::LineEdit.new(self)
    @input_save.setText(".conf")
    @input_save.setReadOnly(true)
    button_go = Qt::PushButton.new('Go !')
    button_quit = Qt::PushButton.new('Quit !')

    #Put all in a grid
    grid = Qt::GridLayout.new(self)
    grid.addWidget(welcome, 0, 0, 1, 3)
    grid.addWidget(repopnourriture, 1, 0, 1, 1)
    grid.addWidget(@popnourriture, 1, 1, 1, 1)
    grid.addWidget(repoplinemate, 2, 0, 1, 1)
    grid.addWidget(@poplinemate, 2, 1, 1, 1)
    grid.addWidget(repopderaumere, 3, 0, 1, 1)
    grid.addWidget(@popderaumere, 3, 1, 1, 1)
    grid.addWidget(repopsibur, 4, 0, 1, 1)
    grid.addWidget(@popsibur, 4, 1, 1, 1)
    grid.addWidget(repopmendiane, 5, 0, 1, 1)
    grid.addWidget(@popmendiane, 5, 1, 1, 1)
    grid.addWidget(repopphiras, 6, 0, 1, 1)
    grid.addWidget(@popphiras, 6, 1, 1, 1)
    grid.addWidget(repopthystame, 7, 0, 1, 1)
    grid.addWidget(@popthystame, 7, 1, 1, 1)

    grid.addWidget(maxnourriture, 1, 2, 1, 1)
    grid.addWidget(@maxnourriture, 1, 3, 1, 1)
    grid.addWidget(maxlinemate, 2, 2, 1, 1)
    grid.addWidget(@maxlinemate, 2, 3, 1, 1)
    grid.addWidget(maxderaumere, 3, 2, 1, 1)
    grid.addWidget(@maxderaumere, 3, 3, 1, 1)
    grid.addWidget(maxsibur, 4, 2, 1, 1)
    grid.addWidget(@maxsibur, 4, 3, 1, 1)
    grid.addWidget(maxmendiane, 5, 2, 1, 1)
    grid.addWidget(@maxmendiane, 5, 3, 1, 1)
    grid.addWidget(maxphiras, 6, 2, 1, 1)
    grid.addWidget(@maxphiras, 6, 3, 1, 1)
    grid.addWidget(maxthystame, 7, 2, 1, 1)
    grid.addWidget(@maxthystame, 7, 3, 1, 1)

    grid.addWidget(savefile, 8, 1, 1, 1)
    grid.addWidget(@input_save, 8, 2, 1, 1)
    grid.add_widget(button_go, 9, 1, 1, 1)
    grid.add_widget(button_quit, 9, 2, 1, 1)

    #put the signal catch for the button
    connect(button_quit, SIGNAL('clicked()'), $qApp, SLOT('quit()'))
    connect(button_go, SIGNAL('clicked()'), self, SLOT("launch_script()"))
  end

  def   launch_script
    if (@popnourriture.value <= 0 || @poplinemate.value <= 0 || @popderaumere.value <= 0 || @popsibur.value <= 0 || @popmendiane.value <= 0 || @popphiras.value <= 0 || @popthystame.value <= 0 || @maxnourriture.value <= 0 || @maxlinemate.value <= 0 || @maxderaumere.value <= 0 || @maxsibur.value <= 0 || @maxmendiane.value <= 0 || @maxphiras.value <= 0 || @maxthystame.value <= 0)
      Qt::MessageBox.critical self, "Error", "Input need to be > 0 !"
      return
    end

    #try to open the file, if it doesn't work, try to create the file, if it doesn't again, a warning pop up
    begin
      @file_save = File.open(@input_save.text, "w+")
    rescue
      begin
        @file_save = File::new(@input_save.text, "w+")
      rescue
        Qt::MessageBox.critical self, "Error", "Cannot open the save file !"
        return
      end
    end

    #now with our files, we can call the script
    self.script
  end

  def   script
    @file_save.write "PopNourriture:" + @popnourriture.text + "\n"
    @file_save.write "PopLinemate:" + @poplinemate.text + "\n"
    @file_save.write "PopDeraumere:" + @popderaumere.text + "\n"
    @file_save.write "PopSibur:" + @popsibur.text + "\n"
    @file_save.write "PopMendiane:" + @popmendiane.text + "\n"
    @file_save.write "PopPhiras:" + @popphiras.text + "\n"
    @file_save.write "PopThystame:" + @popthystame.text + "\n"
    @file_save.write "MaxNourriture:" + @maxnourriture.text + "\n"
    @file_save.write "MaxLinemate:" + @maxlinemate.text + "\n"
    @file_save.write "MaxDeraumere:" + @maxderaumere.text + "\n"
    @file_save.write "MaxSibur:" + @maxsibur.text + "\n"
    @file_save.write "MaxMendiane:" + @maxmendiane.text + "\n"
    @file_save.write "MaxPhiras:" + @maxphiras.text + "\n"
    @file_save.write "MaxThystame:" + @maxthystame.text + "\n"
    @file_save.close
  end
end

app = Qt::Application.new ARGV
QtApp.new
app.exec
