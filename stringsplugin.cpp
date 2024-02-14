#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>

class StringsPlugin : public Fl_Window {
public:
  StringsPlugin(int w, int h, const char* title) : Fl_Window(w, h, title) {
    box = new Fl_Box(20, 40, w-40, h-80, "Strings Plugin");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);

    playButton = new Fl_Button(w/2-60, h-40, 120, 30, "Play");
    playButton->callback(play_cb, this);

    volumeSlider = new Fl_Slider(20, h-40, w-260, 30);
    volumeSlider->type(FL_HOR_SLIDER);
    volumeSlider->range(0.0, 1.0);
    volumeSlider->step(0.01);
    volumeSlider->value(0.5);
    volumeSlider->align(FL_ALIGN_RIGHT);

    end();
  }

  static void play_cb(Fl_Widget* widget, void* data) {
    StringsPlugin* plugin = static_cast<StringsPlugin*>(data);
    double volume = plugin->volumeSlider->value();
    // play the strings sound at the specified volume
  }

private:
  Fl_Box* box;
  Fl_Button* playButton;
  Fl_Slider* volumeSlider;
};

int main(int argc, char** argv) {
  StringsPlugin* plugin = new StringsPlugin(300, 180, "Strings Plugin");
  plugin->show(argc, argv);
  return Fl::run();
}
