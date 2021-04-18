Devoir des clefs :
Trouver dans le dossier "Images" une capture d'écran d'une exécution qui fonctionne sous Python (mais sans la création de la clef publique).
Dans le dossier clef le code (complet avec création de la clef publique) fonctionne en C++ mais problème d'import en Python.

# python_cpp
Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd hello
make
```

Pour utiliser
```
python3
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> hello_component.getVersion()
'1.0'
>>> 
```
