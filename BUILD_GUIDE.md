# Build System Quick Reference

## 🚀 New Build Targets

### Recommended Commands

```bash
# For development (recommended)
make build          # Builds project and cleans object files automatically

# For clean rebuild  
make rebuild         # Full clean → build → cleanup

# For quick compilation
make                 # Standard build (leaves .o files)
```

### Cleanup Commands

```bash
make clean-obj       # Remove only object files (keep executable & libraries)
make clean           # Remove all artifacts except executable
make fclean          # Remove everything including executable
```

### What Gets Cleaned

| Target | Object Files | Libraries | Executable | Description |
|--------|--------------|-----------|------------|-------------|
| `clean-obj` | ✅ | ❌ | ❌ | Lightweight cleanup |
| `clean` | ✅ | ✅ | ❌ | Standard cleanup |
| `fclean` | ✅ | ✅ | ✅ | Complete cleanup |

## 💡 Benefits

- **Cleaner directory**: No scattered `.o` files after successful builds
- **Faster git operations**: Fewer files to track/ignore
- **Better organization**: Only keep what you need
- **Automatic**: No need to remember manual cleanup

## 🔧 Under the Hood

The `build` target:

1. Compiles all source files
2. Links libraries and creates executable  
3. Automatically removes object files on success
4. Provides clear success/failure feedback

Example output:

```text
✅ Build successful! Executable: cub3D
🧹 Cleaning up object files...
✅ Object files cleaned!
```

## ⚡ Pro Tips

- Use `make build` for daily development
- Use `make rebuild` when switching branches
- Libraries are preserved for faster incremental builds
- Object cleanup only happens on successful builds
