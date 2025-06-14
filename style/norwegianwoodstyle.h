#pragma once

#include <QStyle>
#include <QStyleOption>
#include <QPalette>
#include <QWidget>
#include <QPixmap>
#include <qstyle.h>

//QT_BEGIN_NAMESPACE
//class QPainterPath;
//
//class QPushButton;
//
//QT_END_NAMESPACE

class NorwegianWoodStyle final : public QStyle {
	Q_OBJECT

public:
	NorwegianWoodStyle();

	void polish(QPalette& palette);

	void polish(QWidget* widget);

	void unpolish(QWidget* widget);

	int pixelMetric(PixelMetric metric, const QStyleOption* option,
		const QWidget* widget) const;

	int styleHint(StyleHint hint, const QStyleOption* option,
		const QWidget* widget, QStyleHintReturn* returnData) const;

	virtual void drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const override;

	void drawControl(ControlElement control, const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const;

	QRect subElementRect(SubElement subElement, const QStyleOption* option, const QWidget* widget) const override;

	void drawComplexControl(ComplexControl cc, const QStyleOptionComplex* opt, QPainter* p,
		const QWidget* widget) const override;

	SubControl hitTestComplexControl(ComplexControl cc, const QStyleOptionComplex* opt, const QPoint& pt,
		const QWidget* widget) const override;

	QRect subControlRect(ComplexControl cc, const QStyleOptionComplex* opt, SubControl sc,
		const QWidget* widget) const override;

	QSize sizeFromContents(ContentsType ct, const QStyleOption* opt, const QSize& contentsSize,
		const QWidget* w) const override;

	QPixmap
		standardPixmap(StandardPixmap standardPixmap, const QStyleOption* opt, const QWidget* widget) const override;

	QIcon standardIcon(StandardPixmap standardIcon, const QStyleOption* option, const QWidget* widget) const override;

	QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap& pixmap, const QStyleOption* opt) const override;

	int layoutSpacing(QSizePolicy::ControlType control1, QSizePolicy::ControlType control2, Qt::Orientation orientation,
		const QStyleOption* option, const QWidget* widget) const override;

private:
	static void setTexture(QPalette& palette, QPalette::ColorRole role,
		const QPixmap& pixmap);

	static void setBrush(QPalette& palette, QPalette::ColorRole role,
		const QBrush& pixmap);

	void drawButton(PrimitiveElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const;

	void drawFrame(PrimitiveElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget,
		const QPixmap& border) const;

	void drawTab(const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const;

	void drawRect(QPainter* p, QRect r, const QPixmap& pix) const;

	void drawCBox(ControlElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const;

	QPixmap buttonBase, buttonBack[2],
		frmBase, frameBack, ckBoxCheck, paperBack;

	void drawMWidget(const QStyleOption* option,
		QPainter* painter, const QWidget* widget) const;

public:
	NorwegianWoodStyle(const QPixmap& buttonBase, const QPixmap buttonBack[],
		const QPixmap& frmBase, const QPixmap& frameBack,
		const QPixmap& ckBoxCheck, const QPixmap& paperBack);
};


