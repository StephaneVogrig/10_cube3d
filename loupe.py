import tkinter as tk
from PIL import ImageGrab, ImageTk
import sys

class Magnifier:
    def __init__(self, zoom=2, size=200):
        self.zoom = zoom
        self.size = size
        self.root = tk.Tk()
        self.root.overrideredirect(True)
        self.label = tk.Label(self.root)
        self.label.pack()

        self.update_magnifier()
        self.root.mainloop()

    def update_magnifier(self):
        x, y = self.root.winfo_pointerxy()
        bbox = (x - self.size // 2, y - self.size // 2, x + self.size // 2, y + self.size // 2)
        img = ImageGrab.grab(bbox)
        img = img.resize((self.size * self.zoom, self.size * self.zoom), ImageGrab.Image.NEAREST)
        img = ImageTk.PhotoImage(img)
        self.label.config(image=img)
        self.label.image = img

        self.root.geometry('+{}+{}'.format(x + 20, y + 20))
        self.root.after(100, self.update_magnifier)

if __name__ == "__main__":
    zoom_level = 17
    window_size = 10
    if len(sys.argv) == 3:
        zoom_level = int(sys.argv[1])
        window_size = int(sys.argv[2])

    Magnifier(zoom=zoom_level, size=window_size)