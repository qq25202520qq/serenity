#pragma once

#include <LibGUI/GWidget.h>
#include <SharedGraphics/StylePainter.h>
#include <AK/AKString.h>
#include <AK/Function.h>
#include <SharedGraphics/GraphicsBitmap.h>

class GButton : public GWidget {
public:
    explicit GButton(GWidget* parent);
    virtual ~GButton() override;

    String caption() const { return m_caption; }
    void set_caption(const String&);

    void set_icon(RetainPtr<GraphicsBitmap>&& icon) { m_icon = move(icon); }
    const GraphicsBitmap* icon() const { return m_icon.ptr(); }
    GraphicsBitmap* icon() { return m_icon.ptr(); }

    Function<void(GButton&)> on_click;

    void set_button_style(ButtonStyle style) { m_button_style = style; }
    ButtonStyle button_style() const { return m_button_style; }

    void click();

    virtual const char* class_name() const override { return "GButton"; }

private:
    virtual void paint_event(GPaintEvent&) override;
    virtual void mousedown_event(GMouseEvent&) override;
    virtual void mouseup_event(GMouseEvent&) override;
    virtual void mousemove_event(GMouseEvent&) override;
    virtual void enter_event(GEvent&) override;
    virtual void leave_event(GEvent&) override;

    String m_caption;
    RetainPtr<GraphicsBitmap> m_icon;
    ButtonStyle m_button_style { ButtonStyle::Normal };
    bool m_being_pressed { false };
    bool m_hovered { false };
};

