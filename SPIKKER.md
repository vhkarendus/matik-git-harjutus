# Git – spikker

> **Kui seda pole GitHubis, siis seda pole olemas.**

## Üks kord arvuti kohta (seadistus)

```
git config --global user.name "Eesnimi Perenimi"
git config --global user.email "sinu-github-email@näide.ee"
git config --global core.editor "code --wait"
git config --global pull.rebase false
```

## Üks kord projekti kohta (kloonimine)

```
cd ~/Documents
git clone https://github.com/KASUTAJA/REPO.git
cd REPO
code -r .
```

## Iga tööpäev

| Millal | Käsk | Mida teeb |
|---|---|---|
| **Alguses** | `git pull` | toob tiimi uusimad muudatused |
| Töö ajal | `git status` | mis on muutunud? (punane = muudetud, roheline = valmis salvestamiseks) |
| | `git diff` | mis täpselt muutus? |
| | `git add fail` või `git add .` | vali, mis läheb järgmisse salvestuspunkti |
| | `git commit -m "Mis ja miks"` | tee salvestuspunkt |
| | `git log --oneline` | vaata ajalugu |
| **Lõpus** | `git push` | saada GitHubi |

## Ajamasin

| Olukord | Käsk |
|---|---|
| Rikkusin faili, **commit'i pole veel teinud** | `git restore fail` |
| Panin `git add`-iga vale faili | `git restore --staged fail` |
| Tegin vale **commit'i** | `git revert HEAD --no-edit` (tekib uus commit, mis tühistab eelmise) |

## Kui midagi läheb viltu

| Näed | Tähendab | Tee |
|---|---|---|
| `! [rejected] ... (fetch first)` | Keegi saatis enne sind | `git pull`, siis uuesti `git push` |
| `CONFLICT (content): Merge conflict in ...` | Kaks inimest muutis sama rida | Ava fail → vali õige versioon → salvesta → `git add fail` → `git commit -m "Lahendasin konflikti"` → `git push` |
| VS Code'is avanes vahekaart `MERGE_MSG` | Git tahab ühendamisele sõnumit | Sulge vahekaart (✕) – vaikimisi sõnum sobib |
| Terminal on imelik, all `~ ~ ~` (Vim) | Avanes vana tekstiredaktor | Vajuta `Esc`, kirjuta `:wq`, vajuta `Enter` |
| `fatal: not a git repository` | Sa ei ole repo kaustas | `cd` õigesse kausta |
| `Need to specify how to reconcile divergent branches` | Seadistus puudu | `git config --global pull.rebase false`, siis `git pull` |
| Konflikti lahendamine läks sassi | – | `git merge --abort` (tagasi olukorda enne `pull`-i) |

## Hea commit'i sõnum

- ✅ `Lisasin temperatuurianduri lugemise`
- ✅ `Parandasin: servo värises 90° juures`
- ❌ `muudatused` · ❌ `asdf` · ❌ `test2`

**Reegel:** sõnum lõpetab lause *„See commit …“*.

## Tiimi 5 reeglit

1. **Alusta** alati `git pull`-iga.
2. **Commit'i väikeste sammudena** – üks mõte = üks commit.
3. **Lõpeta** alati `git push`-iga. Kui seda pole GitHubis, siis seda pole olemas.
4. **Ütle tiimile**, millist faili muudad.
5. **Paroolid, API-võtmed ja suured videod ei lähe GitHubi** – kasuta `.gitignore`-i.

## Boonus: harud ja Pull Request

```
git switch -c minu-haru          # uus haru ja kohe sinna
# ... muuda, add, commit ...
git push -u origin minu-haru     # saada haru GitHubi
```

GitHubis: **Compare & pull request** → kirjuta, mida tegid → **Create pull request**. Tiimikaaslane vaatab üle → **Merge pull request**.

```
git switch main                  # tagasi põhiharule
git pull                         # too ühendatud muudatus
```
