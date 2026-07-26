# -*- coding: utf-8 -*-
# sATypeMove_Table is [17] -> max 16 chars. Shorten "un moviment X" to "un mov. X".
KIND = 'c'
FILES = ['src/battle_message.c']
T = { f"un moviment {t}": f"un mov. {t}" for t in
      ["Normal","Lluita","Volador","Verí","Terra","Roca","Insecte","Fantasma",
       "Acer","???","Foc","Aigua","Planta","Elèctric","Psíquic","Gel","Drac",
       "Sinistre","Fada"] }
