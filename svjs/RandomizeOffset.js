function getClientInfo() {
    return {
      "name" : SV.T("[GT] Randomize Notes' Offset"),
      "author" : "Grog Tony",
      "versionNumber" : 1,
      "minEditorVersion" : 65540
    };
  }

function getTranslations(langCode) {
    if(langCode == "zh-cn") {
        return [
        ["[GT] Randomize Notes' Offset", "[GT] 随机化音符起始时间"],
        ["Randomize Notes' Offset", "随机化音符起始时间"],
        ["Offset range", "最大偏移量"]
        ];
    }
    return [];
}

function randomRange(left, right){
    return left + (right - left) * Math.random();
}

function randomize(range){

    // Get the current selection, scope (group reference) and its target group.
    var selection = SV.getMainEditor().getSelection();
    var selectedNotes = selection.getSelectedNotes();
    
    for(var i = 0; i < selectedNotes.length; i ++) {
        var note = selectedNotes[i];
        var newOffset = randomRange(-range , range);
        note.setAttributes({
            "tNoteOffset" : newOffset
        });
    }
}
function main() {
    var form = {
        "title"   : SV.T("Randomize Notes' Offset"),
        "message" : "",
        "buttons" : "OkCancel",
        "widgets" : [
          {
            "name"     : "range",
            "type"     : "Slider",
            "label"    : SV.T("Offset range"),
            "format"   : "%.3f",
            "minValue" : 0,
            "maxValue" : 0.1,
            "interval" : 0.001,
            "default"  : 0.02
          }
        ]
    };
    var results = SV.showCustomDialog(form);

    if(results.status)
        randomize(results.answers.range);
    
    SV.finish();
}
